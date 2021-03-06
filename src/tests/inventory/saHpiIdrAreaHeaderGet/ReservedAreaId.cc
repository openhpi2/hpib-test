/*
 * (C) Copyright University of New Hampshire, 2006
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
 *     Donald A. Barre <dbarre@unh.edu>
 */

#include "ReservedAreaId.h"

using namespace ns_saHpiIdrAreaHeaderGet;

/*****************************************************************************
 * Constructor
 *****************************************************************************/

ReservedAreaId::ReservedAreaId(char *line) : IdrTestCase(line) {
}

/*****************************************************************************
 * Return the name of the test case.
 *****************************************************************************/

const char *ReservedAreaId::getName() {
    return "ReservedAreaId";
}
/*****************************************************************************
 * Return the description of the test case.
 *****************************************************************************/

const char *ReservedAreaId::getDescription() {
    return "The <i>AreaId</i> is an invalid reserved\n"
           "value such as SAHPI_LAST_ENTRY.";
}

/*****************************************************************************
 * Return the precondition of the test case.
 *****************************************************************************/

const char *ReservedAreaId::getPrecondition() {
    return "Requires an Inventory.";
}

/*****************************************************************************
 * Return the expected error code.
 *****************************************************************************/

SaErrorT ReservedAreaId::getExpectedReturn() {
    return SA_ERR_HPI_INVALID_PARAMS;
}

/*****************************************************************************
 * Run the test.
 *****************************************************************************/

HpiTestStatus ReservedAreaId::runIdrTest(SaHpiSessionIdT sessionId,
                                         SaHpiRptEntryT *rptEntry,
                                         SaHpiInventoryRecT *idrRec) {
    HpiTestStatus status;
    SaHpiEntryIdT nextAreaId;
    SaHpiIdrAreaHeaderT header;

    SaErrorT error = saHpiIdrAreaHeaderGet(sessionId,
                                           rptEntry->ResourceId,
                                           idrRec->IdrId,    
                                           SAHPI_IDR_AREATYPE_UNSPECIFIED,
                                           SAHPI_LAST_ENTRY,
                                           &nextAreaId, &header);
    if (error == SA_ERR_HPI_NOT_PRESENT) {
        status.assertNotSupport();
    } else if (error == SA_ERR_HPI_INVALID_PARAMS) {
        status.assertPass();
    } else {
        status.assertFailure(TRACE, IDR_AREA_HEADER_GET,
                             SA_ERR_HPI_INVALID_PARAMS, error);
    } 

    return status;
}

