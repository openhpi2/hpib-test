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

#include "NoCapability.h"

using namespace ns_saHpiSensorEventMasksSet;

/*****************************************************************************
 * Constructor
 *****************************************************************************/

NoCapability::NoCapability(char *line)
: HpiNoCapabilityTestCase(line, "Sensor") {
}

/*****************************************************************************
 * Run the test.
 *****************************************************************************/

HpiTestStatus NoCapability::runResourceTest(SaHpiSessionIdT sessionId,
                                            SaHpiRptEntryT *rptEntry) {
    HpiTestStatus status;

    if (hasSensorCapability(rptEntry)) {
        status.assertNotSupport();
    } else {
        SaErrorT error = saHpiSensorEventMasksSet(sessionId,
                                                  rptEntry->ResourceId,
                                                  getValidSensorNum(), 
                                                  SAHPI_SENS_ADD_EVENTS_TO_MASKS,
                                                  0x0, 0x0);
        if (error == SA_ERR_HPI_CAPABILITY) {
            status.assertPass();
        } else {
            status.assertFailure(TRACE, SENSOR_EVENT_MASKS_SET,
                                 SA_ERR_HPI_CAPABILITY, error);
        }
    }

    return status;
}
