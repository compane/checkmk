// +------------------------------------------------------------------+
// |             ____ _               _        __  __ _  __           |
// |            / ___| |__   ___  ___| | __   |  \/  | |/ /           |
// |           | |   | '_ \ / _ \/ __| |/ /   | |\/| | ' /            |
// |           | |___| | | |  __/ (__|   <    | |  | | . \            |
// |            \____|_| |_|\___|\___|_|\_\___|_|  |_|_|\_\           |
// |                                                                  |
// | Copyright Mathias Kettner 2009             mk@mathias-kettner.de |
// +------------------------------------------------------------------+
// 
// This file is part of Check_MK.
// The official homepage is at http://mathias-kettner.de/check_mk.
// 
// check_mk is free software;  you can redistribute it and/or modify it
// under the  terms of the  GNU General Public License  as published by
// the Free Software Foundation in version 2.  check_mk is  distributed
// in the hope that it will be useful, but WITHOUT ANY WARRANTY;  with-
// out even the implied warranty of  MERCHANTABILITY  or  FITNESS FOR A
// PARTICULAR PURPOSE. See the  GNU General Public License for more de-
// ails.  You should have  received  a copy of the  GNU  General Public
// License along with GNU Make; see the file  COPYING.  If  not,  write
// to the Free Software Foundation, Inc., 51 Franklin St,  Fifth Floor,
// Boston, MA 02110-1301 USA.

#ifndef TableLog_h
#define TableLog_h

#include <map>
#include <time.h>
#include "config.h"
#include "Table.h"

class Logfile;

class TableLog : public Table
{
    typedef map<time_t, Logfile *> _logfiles_t;
    _logfiles_t _logfiles;
    pthread_mutex_t _lock;
    time_t _last_index_update;
    unsigned long _num_cached_messages;
    unsigned long _max_cached_messages;

public:
    TableLog(unsigned long max_cached_messages);
    ~TableLog();
    const char *name() { return "log"; };
    void handleNewMessage(Logfile *logfile, time_t since, time_t until, unsigned logclasses);
    void answerQuery(Query *query);

private:
    void forgetLogfiles();
    void updateLogfileIndex();
    void scanLogfile(char *path, bool watch);
    bool answerQuery(Query *, Logfile *, time_t, time_t);
    _logfiles_t::iterator findLogfileStartingBefore(time_t);
    void dumpLogfiles();
};

#endif // TableLog_h
