.. index:: ! grdedit
.. include:: module_core_purpose.rst_

*******
grdedit
*******

|grdedit_purpose|

Synopsis
--------

.. include:: common_SYN_OPTs.rst_

**gmt grdedit** *ingrid*
[ |-A| ]
[ |-C|\ **b**\|\ **c**\|\ **n**\|\ **p** ]
[ |SYN_OPT-D2| ]
[ |-E|\ [**a**\|\ **e**\|\ **h**\|\ **l**\|\ **r**\|\ **t**\|\ **v**] ]
[ |-G|\ *outgrid* ]
[ |-J|\ *parameters* ]
[ |-L|\ [**+n**\|\ **p**] ]
[ |-N|\ *table* ]
[ |SYN_OPT-R| ]
[ |-S| ] [ |-T| ]
[ |SYN_OPT-V| ]
[ |SYN_OPT-bi| ]
[ |SYN_OPT-di| ]
[ |SYN_OPT-e| ]
[ |SYN_OPT-f| ]
[ |SYN_OPT-h| ]
[ |SYN_OPT-i| ]
[ |SYN_OPT-w| ]
[ |SYN_OPT-:| ]
[ |SYN_OPT--| ]

|No-spaces|

Description
-----------

**grdedit** reads the header information in a binary 2-D grid file and
replaces the information with values provided on the command line [if
any]. As an option, global, geographical grids (with 360 degrees
longitude range) can be rotated in the east-west direction, and
individual nodal values can be replaced from a table of *x*, *y*, *z*
values. **grdedit** only operates on files containing a grid header. **Note**:
If it is important to retain the original data you should use **-G**
to save the modified grid to a new file.

Required Arguments
------------------

.. |Add_ingrid| replace:: Name of the 2-D grid file to modify.
.. include:: explain_grd_inout.rst_
    :start-after: ingrid-syntax-begins
    :end-before: ingrid-syntax-ends

Optional Arguments
------------------

.. _-A:

**-A**
    If necessary, adjust the file's *x_inc*, *y_inc* to be compatible
    with its domain (or a new domain set with **-R**). Older grid files
    (i.e., created prior to GMT 3.1) often had excessive slop in
    *x_inc*, *y_inc* and an adjustment is necessary. Newer files are
    created correctly.

.. _-C:

**-Cb**\|\ **c**\|\ **n**\|\ **p**
    Normally, output grids store the current module's command-line history.
    Use **-C** to specify what the output grid's command history should be:
    Append directive **b** to write both the previous and the current module's 
    command histories, **c** to only write the current module's command
    history, **n** to save no history whatsoever [Default], or select **p**
    to instead save only the previous command history.

.. _-D:

.. include:: explain_-D_cap.rst_

.. _-E:

**-E**\ [**a**\|\ **e**\|\ **h**\|\ **l**\|\ **r**\|\ **t**\|\ **v**]
    Transform the grid in one of six ways and (for **l**\|\ **r**\|\ **t**)
    interchange the *x* and *y* information:
    **-Ea** will flip the grid both horizontally and vertically,
    **-Ee** will exchange the x (longitude) and y (latitude) dimensions,
    **-Eh** will flip the grid horizontally (left-to-right),
    **-El** will rotate the grid 90 degrees counter-clockwise (left),
    **-Er** will rotate the grid 90 degrees clockwise (right),
    **-Et** will transpose the grid [Default],
    **-Ev** will flip the grid vertically (top-to-bottom).
    Incompatible with the other options (except **-G**).

.. _-G:

.. |Add_outgrid| replace:: Normally, **grdedit** will overwrite the existing grid with the modified grid.
    Use **-G** to write the modified grid to the file *outgrid* instead.
.. include:: /explain_grd_inout.rst_
    :start-after: outgrid-syntax-begins
    :end-before: outgrid-syntax-ends

.. |Add_-J| replace:: Use the **-J** syntax to save the georeferencing info as CF-1 compliant
    metadata in netCDF grids. This metadata will be recognized by GDAL.
.. include:: explain_-J.rst_
    :start-after: **Syntax**
    :end-before: **Description**

.. _-L:

**-L**\ [**+n**\|\ **p**]
    Adjust the longitude values in the grid (only applies to geographic grids).  By default we will
    try to adjust *west* and *east* so that *west* >= -180 or *east* <= +180, but this depends on
    the range of the longitudes. Append **+n** to force negative longitude values and **+p** to
    force positive longitude values.

.. _-N:

**-N**\ *table*
    Read the ASCII (or binary; see **-bi**) file
    *table* and replace the corresponding nodal values in the grid with
    these *x*,\ *y*,\ *z* values.

.. |Add_-R| replace:: The new w/e/s/n values will replace those in the grid, and the *x_inc*, *y_inc* values are
    adjusted, if necessary. |Add_-R_links|
.. include:: explain_-R.rst_
    :start-after: **Syntax**
    :end-before: **Description**

.. _-S:

**-S**
    For global, geographical grids only. Grid values will be shifted
    longitudinally according to the new borders given in **-R**.

.. _-T:

**-T**
    Make necessary changes in the header to convert a
    gridline-registered grid to a pixel-registered grid, or vice-versa.
    Basically, gridline-registered grids will have their domain extended
    by half the x- and y-increments whereas pixel-registered grids will
    have their domain shrunk by the same amount.
    This is a *non-destructive* grid change; see :ref:`Switching registrations <Switch_Registrations>`.

.. |Add_-V| replace:: |Add_-V_links|
.. include:: explain_-V.rst_
    :start-after: **Syntax**
    :end-before: **Description**

.. |Add_-bi| replace:: [Default is 3 input columns].
.. include:: explain_-bi.rst_

.. |Add_-di| unicode:: 0x20 .. just an invisible code
.. include:: explain_-di.rst_

.. |Add_-e| unicode:: 0x20 .. just an invisible code
.. include:: explain_-e.rst_

.. |Add_-f| unicode:: 0x20 .. just an invisible code
.. include:: explain_-f.rst_

.. |Add_-h| unicode:: 0x20 .. just an invisible code
.. include:: explain_-h.rst_

.. include:: explain_-icols.rst_

.. include:: explain_-w.rst_

.. include:: explain_help.rst_

.. include:: explain_grd_coord.rst_

Examples
--------

.. include:: explain_example.rst_

Let us assume the file data.nc covers the area 300/310/10/30. We want to
change the boundaries from geodetic longitudes to geographic and put a
new title in the header. We accomplish this by::

    gmt grdedit data.nc -R-60/-50/10/30 -D+t"Gravity Anomalies"

The grid world.nc has the limits 0/360/-72/72. To shift the data so that
the limits would be -180/180/-72/72, use::

    gmt grdedit world.nc -R-180/180/-72/72 -S

The file junk.nc was created prior to GMT 3.1 with incompatible
**-R** and **-I** arguments. To reset the x- and y-increments we run::

    gmt grdedit junk.nc -A

The file junk.nc was created prior to GMT 4.1.3 and does not contain
the required information to indicate that the grid is geographic. To add
this information, run::

    gmt grdedit junk.nc -fg

To rotate the grid oblique.nc 90 degrees counter-clockwise and write out
the rotated grid to a new file, run::

    gmt grdedit oblique.nc -El -Goblique_rot.nc


To ensure that the grid depths.nc only has positive longitude values, run::

    gmt grdedit depths.nc -L+p

The grid bad.nc has latitude as x-coordinates an longitude as y-coordinates.
We can exchange the two dimension by running::

    gmt grdedit bad.nc -Ee -Gnew.nc

Notes:
------

This module is not a general editor for netCDF files.  If your netCDF file
contains more than one 2-D (or higher dimension) data layer, then only the
selected layer will be written out if changes are requested.  Likewise,
if you have additional netCDF attributes then those will also be lost in
any revised output.

See Also
--------

:doc:`gmt`,
:doc:`grd2xyz`,
:doc:`grdfill`,
:doc:`grdinfo`,
:doc:`xyz2grd`
