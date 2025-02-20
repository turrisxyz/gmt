.. index:: ! pssegyz
.. include:: ../module_supplements_purpose.rst_

*******
pssegyz
*******

|pssegyz_purpose|

Synopsis
--------

.. include:: ../../common_SYN_OPTs.rst_

**gmt pssegyz** *SEGYfile* |-J|\ *parameters*
|-J|\ **z**\|\ **Z**\ *parameters*
|SYN_OPT-Rz|
|-D|\ *deviation* |-F|\ [*color*] **-W**
[ |-C|\ *clip* ]
[ |-I| ] [ |-K| ] [ |-L|\ *nsamp* ]
[ |-M|\ *ntrace* ]
[ |-N| ]
[ |-O| ]
[ |-P| ]
[ |-Q|\ *<mode><value>* ]
[ |-S|\ *header_x*/*header_y* ]
[ |SYN_OPT-U| ]
[ |SYN_OPT-V| ]
[ |SYN_OPT-X| ]
[ |SYN_OPT-Y| ]
[ |-Z| ]
[ |SYN_OPT-p| ]
[ |SYN_OPT-t| ]
[ |SYN_OPT--| ]

.. include:: segyz.rst
    :start-after: .. module_common_begins
    :end-before: .. module_common_ends

.. include:: ../../common_classic.rst_

Examples
--------

To plot the SEGY file wa1.segy with normalized traces plotted at true
offset locations, clipped at ±3 and with wiggle trace and positive
variable area shading in black, use

   ::

    gmt pssegyz wa1.segy -JX5i/-5i -D1 -Jz0.05i -E180/5 -R0/100/0/10/0/10 \
            -C3 -N -So -W -Fblack > segy.ps

.. include:: segyz.rst
    :start-after: .. module_note_begins
    :end-before: .. module_note_ends

See Also
--------

:doc:`gmt </gmt>`, :doc:`pssegy`, :doc:`segy2grd`
