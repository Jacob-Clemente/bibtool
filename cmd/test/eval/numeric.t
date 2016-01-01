#!/bin/perl -W
# =============================================================================
#  
#  This file is part of BibTool.
#  It is distributed under the GNU General Public License.
#  See the file COPYING for details.
#  
#  (c) 2015 Gerd Neugebauer
#  
#  Net: gene@gerd-neugebauer.de
#  
#*=============================================================================

=head1 NAME

numeric.t - Test suite for BibTool numeric values.

=head1 SYNOPSIS

numeric.t

=head1 DESCRIPTION

This module contains some test cases. Running this module as program
will run all test cases and print a summary for each. Optionally files
*.out and *.err are left if the expected result does not match the
actual result.

=head1 OPTIONS

none

=head1 AUTHOR

Gerd Neugebauer

=cut

use strict;
use BUnit;

#------------------------------------------------------------------------------
BUnit::run(name         => 'eval/numeric-0',
	   args	        => '--eval',
	   resource     => <<__EOF__ ,
0;
__EOF__
	   expected_err => '',
	   expected_out => <<__EOF__ );
0
__EOF__

#------------------------------------------------------------------------------
BUnit::run(name         => 'eval/numeric-1',
	   args	        => '--eval',
	   resource	=> <<__EOF__ ,
123;
__EOF__
	   expected_err => '',
	   expected_out => <<__EOF__ );
123
__EOF__

#------------------------------------------------------------------------------
BUnit::run(name         => 'eval/numeric-2',
	   args	        => '--eval',
	   resource	=> <<__EOF__ ,
-123;
__EOF__
	   expected_err => '',
	   expected_out => <<__EOF__ );
-123
__EOF__

1;
#------------------------------------------------------------------------------
# Local Variables: 
# mode: perl
# End: 
