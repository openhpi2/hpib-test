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

#ifndef __RUNNING_H__
#define __RUNNING_H__

#include "WatchdogTestCase.h"

/*****************************************************************************
 * Running Test Case
 *****************************************************************************/

namespace ns_saHpiWatchdogTimerSet
{
    class Running : public WatchdogTestCase
    {
    public:
        Running(char *line);

        HpiTestStatus runWatchdogTest(SaHpiSessionIdT sessionId, 
                                      SaHpiRptEntryT *rptEntry,
                                      SaHpiWatchdogRecT *watchdogRec);

        const char *getName();

        const char *getDescription();

        const char *getPrecondition();

        SaErrorT getExpectedReturn();

    private:

        HpiTestStatus testWatchdog(SaHpiSessionIdT sessionId,
                                   SaHpiRptEntryT *rptEntry,
                                   SaHpiWatchdogNumT watchdogNum,
                                   SaHpiWatchdogT &watchdog);

        HpiTestStatus checkStoppedWatchdog(SaHpiSessionIdT sessionId,
                                           SaHpiResourceIdT resourceId,
                                           SaHpiWatchdogNumT watchdogNum,
                                           SaHpiWatchdogT &watchdog);

        HpiTestStatus checkRunningWatchdog(SaHpiSessionIdT sessionId,
                                           SaHpiResourceIdT resourceId,
                                           SaHpiWatchdogNumT watchdogNum,
                                           SaHpiWatchdogT &watchdog);
    };
}

#endif