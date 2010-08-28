/*
 * (C) Copyright Lars Wetzel, 2009
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with 
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple 
 * Place - Suite 330, Boston, MA 02111-1307 USA.
 *
 * Author(s):
 *     Lars Wetzel <larswetzel@users.sourceforge.net>
 */

#ifndef __FUMITESTCASE_H___
#define __FUMITESTCASE_H___

#include "SafTest.h"
#include "HpiRdrTestCase.h"

/*****************************************************************************
 * HPI Fumi Test Case
 *
 * Run a test that requires some fumi initialization. 
 *****************************************************************************/

class FumiTestCase : public HpiRdrTestCase
{
public:
    FumiTestCase();
    FumiTestCase(char* line);
    
protected:
    HpiTestStatus runRdrTest(SaHpiSessionIdT sessionId,
                             SaHpiRptEntryT *rptEntry, 
                             SaHpiRdrT *rdr);

    virtual HpiTestStatus runFumiTest(SaHpiSessionIdT sessionId, 
                                       SaHpiRptEntryT *rptEntry, 
                                       SaHpiFumiRecT *fumiRec) = 0;

};


#endif
