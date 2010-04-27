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

#include "TestSuite.h"
#include "saHpiAlarmGetNext/TestSuite.h"
#include "saHpiAlarmGet/TestSuite.h"
#include "saHpiAlarmAdd/TestSuite.h"
#include "saHpiAlarmAcknowledge/TestSuite.h"
#include "saHpiAlarmDelete/TestSuite.h"

using namespace ns_alarm;

/*****************************************************************************
 * Constructor
 *****************************************************************************/

TestSuite::TestSuite() { 
    add(new ns_saHpiAlarmGetNext::TestSuite());
    add(new ns_saHpiAlarmGet::TestSuite());
    add(new ns_saHpiAlarmAdd::TestSuite());
    add(new ns_saHpiAlarmAcknowledge::TestSuite());
    add(new ns_saHpiAlarmDelete::TestSuite());
}

/*****************************************************************************
 * Return the name of the test suite.
 *****************************************************************************/

const char *TestSuite::getName() {
    return "Alarm";
}

/*****************************************************************************
 * Return the description of the test suite.
 *****************************************************************************/

const char *TestSuite::getDescription() {
    return "Conformance test suite for Alarms.";
}
