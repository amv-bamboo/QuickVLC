/******************************************************************************
* This file is part of QuickVLC - Qt and libvlc connection library.
* Copyright (C) 2016 Tadej Novak <tadej@tano.si>, 
*               2022 Alexey Avramchik (OU Bamboo group) <aa@bam-boo.eu>
*
* QuickVLC is free software: you can redistribute it and/or modify it 
* under the terms of the GNU General Public License as published 
* by the Free Software Foundation, either version 3 of the License, 
* or (at your option) any later version.
*
* QuickVLC is distributed in the hope that it will be useful, 
* but WITHOUT ANY WARRANTY; without even the implied warranty 
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
* See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License 
* along with QuickVLC. If not, see <https://www.gnu.org/licenses/>.
******************************************************************************/

#include "error.h"

#include <vlc/vlc.h>

Q_LOGGING_CATEGORY(vlc, "vlc.error")

namespace Vlc {

QString Error::errorMsg()
{
    QString error;

    if (libvlc_errmsg()) {
        error = QString::fromUtf8(libvlc_errmsg());
        libvlc_clearerr();
    }

    return error;
}

void Error::printErrorMsg()
{
    QString error = errorMsg();

    if (!error.isEmpty()) {
        qCWarning(vlc) << error;
    }
}

}  // namespace Vlc
