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

#include "GetThresholds.h"
#include "Report.h"
#include "SensorHelper.h"

using namespace ns_saHpiSensorThresholdsGet;

/*****************************************************************************
 * Constructor
 *****************************************************************************/

GetThresholds::GetThresholds(char *line) : ThresholdSensorTestCase(line) {
}

/*****************************************************************************
 * Return the name of the test case.
 *****************************************************************************/

const char *GetThresholds::getName() {
    return "GetThresholds";
}

/*****************************************************************************
 * Return the description of the test case.
 *****************************************************************************/

const char *GetThresholds::getDescription() {
    return "Retrieve the thresholds and verify the threshold values.";
}

/*****************************************************************************
 * Return the precondition of the test case.
 *****************************************************************************/

const char *GetThresholds::getPrecondition() {
    return "Requires a sensor that doesn't return SA_ERR_HPI_ENTITY_NOT_PRESENT.";
}

/*****************************************************************************
 * Return the expected error code.
 *****************************************************************************/

SaErrorT GetThresholds::getExpectedReturn() {
    return SA_OK;
}

/*****************************************************************************
 * Run the test.
 *****************************************************************************/

HpiTestStatus GetThresholds::runThresholdTest(SaHpiSessionIdT sessionId,
                                              SaHpiRptEntryT *rptEntry,
                                              SaHpiSensorRecT *sensorRec) {
    HpiTestStatus status;
    Report report;
    SaHpiSensorThresholdsT sensorThresholds;

    SaErrorT error = saHpiSensorThresholdsGet(sessionId,
                                              rptEntry->ResourceId,
                                              sensorRec->Num,
                                              &sensorThresholds);
    if (error == SA_ERR_HPI_BUSY) {
        status.assertNotSupport();
    } else if (error == SA_ERR_HPI_ENTITY_NOT_PRESENT) {
        status.assertNotSupport();
    } else if (error != SA_OK) {
        status.assertFailure(TRACE, SENSOR_THRESHOLDS_GET, SA_OK, error);
    } else if (!SensorHelper::isValidThresholds(&sensorThresholds, sensorRec, report)) {
        status.assertFailure(TRACE, report.toString());
    } else {
        status.assertPass();
    }

    return status;
}
