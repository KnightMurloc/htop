#ifndef HEADER_Platform
#define HEADER_Platform
/*
htop - openbsd/Platform.h
(C) 2014 Hisham H. Muhammad
(C) 2015 Michael McConville
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "Action.h"
#include "BatteryMeter.h"
#include "SignalsPanel.h"

extern ProcessFieldData Process_fields[];


extern ProcessField Platform_defaultFields[];

extern int Platform_numberOfFields;

/*
 * See /usr/include/sys/signal.h
 */
extern const SignalItem Platform_signals[];

extern const unsigned int Platform_numberOfSignals;

void Platform_setBindings(Htop_Action* keys);

extern MeterClass* Platform_meterTypes[];

// preserved from FreeBSD port
int Platform_getUptime();

void Platform_getLoadAverage(double* one, double* five, double* fifteen);

int Platform_getMaxPid();

double Platform_setCPUValues(Meter* this, int cpu);

void Platform_setMemoryValues(Meter* this);

/*
 * Copyright (c) 1994 Thorsten Lockert <tholo@sigmasoft.com>
 * All rights reserved.
 *
 * Taken almost directly from OpenBSD's top(1)
 */
void Platform_setSwapValues(Meter* this);

void Platform_setTasksValues(Meter* this);

char* Platform_getProcessEnv(pid_t pid);

#endif
