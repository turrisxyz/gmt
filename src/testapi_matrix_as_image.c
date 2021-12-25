#include "gmt.h"

/* Test reading in an image file, then converting to a matrix representation.
 * Then passing the matrix to grdwrite as either a reference or a duplicate.
 * .
 */

int main () {
	unsigned int mode = GMT_SESSION_EXTERNAL;
	uint64_t dim[3] = {0, 0, 3};	/* Three layers */
	struct GMT_IMAGE *I = NULL;
	struct GMT_MATRIX *M = NULL;
	char input[GMT_VF_LEN] = {""};
	char args[256] = {""};
	struct GMTAPI_CTRL *API = NULL;

	API = GMT_Create_Session ("test", 2U, mode, NULL);

	/* Read in an image as rgb 3-layers */
	if ((I = GMT_Read_Data (API, GMT_IS_IMAGE, GMT_IS_FILE, GMT_IS_SURFACE, GMT_CONTAINER_AND_DATA | GMT_IMAGE_NO_INDEX, NULL, "@earth_day_01d_p.tif", NULL)) == NULL) return (EXIT_FAILURE);
	/* Make a matrix|image to hold the image we read */
	dim[GMT_X] = I->header->n_columns;	dim[GMT_Y] = I->header->n_rows;
	if ((M = GMT_Create_Data (API, GMT_IS_IMAGE|GMT_VIA_MATRIX, GMT_IS_SURFACE, GMT_CONTAINER_ONLY, dim, I->header->wesn, I->header->inc, I->header->registration, 0, NULL)) == NULL) return (EXIT_FAILURE);
	GMT_Open_VirtualFile (API, GMT_IS_IMAGE|GMT_VIA_MATRIX, GMT_IS_SURFACE, GMT_IN|GMT_IS_REFERENCE, M, input);
	/* call gmtwrite to write an output image via a referenced matrix */
	sprintf (args, "%s -Ti ->image_via_matrix_reference.tif", input);
	GMT_Call_Module (API, "gmtwrite", GMT_MODULE_CMD, args);
	GMT_Close_VirtualFile (API, input);

	GMT_Open_VirtualFile (API, GMT_IS_IMAGE|GMT_VIA_MATRIX, GMT_IS_SURFACE, GMT_IN|GMT_IS_REFERENCE, M, input);
	/* call gmtwrite to write an output image via a duplicated matrix */
	sprintf (args, "%s -Ti ->image_via_matrix_duplicate.tif", input);
	GMT_Call_Module (API, "gmtwrite", GMT_MODULE_CMD, args);
	GMT_Close_VirtualFile (API, input);

	if (GMT_Destroy_Session (API)) return EXIT_FAILURE;
	exit (0);
}
