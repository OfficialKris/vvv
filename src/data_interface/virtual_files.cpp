/*
	This file is part of VVV (Virtual Volumes View)

	Copyright (C) 2007, the VVV Development team

	Author: Fulvio Senore

    VVV is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    VVV is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with VVV; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "virtual_files.h"

CVirtualFiles::CVirtualFiles(void) {
}

CVirtualFiles::~CVirtualFiles(void) {
}

void CVirtualFiles::DBStartQueryListFiles( long PathID ) {
	wxString sql = "select virtual_files.file_id, virtual_files.virtual_path_id, virtual_files.physical_file_id, virtual_files.virtual_path_file_id, files.file_name, files.file_size, files.file_ext, files.file_datetime, files.path_id, files.path_file_id ";
    sql += "from virtual_files inner join files ";
	sql += "on virtual_files.physical_file_id = files.file_id ";
	sql += "where virtual_files.virtual_path_id = " + long2string(PathID) + " ";
	sql += "order by files.file_name";
	DBStartMultiRowQuery( sql, true );
}

