#include "gmt.h"
int main () {
	void *API;
	struct GMT_DATASET *D1 = NULL;
	char input1[GMT_VF_LEN] = {""};
	char args[128] = {""}; 

	/* Initialize the GMT session */
	API = GMT_Create_Session ("test", 2U, GMT_SESSION_EXTERNAL, NULL);
	/* Read the data */
	if ((D1 = GMT_Read_Data (API, GMT_IS_DATASET, GMT_IS_FILE, GMT_IS_POINT, GMT_READ_NORMAL, NULL, "D1.txt", NULL)) == NULL) return EXIT_FAILURE;
	/* Open a virtual files to hold the data */
	GMT_Open_VirtualFile (API, GMT_IS_DATASET, GMT_IS_POINT, GMT_IN, D1, input1);
	/* Create the parameters string */
	sprintf (args, "%s -Rd -JS0/0/14c -Bpag -BWSen -Sc0.2 -Ggreen -P", input1);
	/* Call the module */
	GMT_Call_Module (API, "psxy", GMT_MODULE_CMD, args);
	/* Free input resources */
	GMT_Close_VirtualFile (API, input1);
	GMT_Destroy_Data (API, &D1);
	/* Destroy session */
	if (GMT_Destroy_Session (API)) return EXIT_FAILURE;
}
