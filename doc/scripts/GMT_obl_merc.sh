#!/usr/bin/env bash
gmt begin GMT_obl_merc
    gmt set GMT_THEME cookbook
    gmt coast -R270/20/305/25+r -JOc280/25.5/22/69/12c -Bag -Di -A250 -Gburlywood -Wthinnest -TdjTR+w1c+f2+l+o0.4c -Sazure --FONT_TITLE=8p --MAP_TITLE_OFFSET=4p
gmt end show

