/******************************************************************************
    Copyright (C) 2013 by Hugh Bailey <obs.jim@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include "util/platform.h"
#include "util/dstr.h"
#include "obs.h"
#include "obs-data.h"

/* on windows, plugin files are located in [base directory]/plugins/[bit] */
char *find_plugin(const char *plugin)
{
	struct dstr path;
	dstr_init_copy(&path, OBS_INSTALL_PREFIX "obs-plugins/");
	dstr_cat(&path, plugin);
	return path.array;
}

/* on windows, points to [base directory]/libobs */
char *find_libobs_data_file(const char *file)
{
	struct dstr path;
	dstr_init_copy(&path, OBS_INSTALL_PREFIX OBS_DATA_PATH "/libobs/");
	dstr_cat(&path, file);
	return path.array;
}

/* on windows, data files should always be in [base directory]/data */
char *obs_find_plugin_file(const char *file)
{
	struct dstr path;
	dstr_init_copy(&path, OBS_INSTALL_PREFIX OBS_DATA_PATH "/obs-plugins/");
	dstr_cat(&path, file);
	return path.array;
}
