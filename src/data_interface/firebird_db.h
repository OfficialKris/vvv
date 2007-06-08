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

#ifndef __FIREBIRD_DB_H__
#define __FIREBIRD_DB_H__

#include <wx/string.h>

#include "base_db.h"
#include "../ibpp/core/ibpp.h"

using namespace std;

class CFirebirdDB :	public CBaseDB {
public:
	CFirebirdDB( wxString serverName, wxString databaseName, wxString userName, wxString password );
	~CFirebirdDB(void);

	wxString Connect(void);
	void Disconnect(void);
	
	// returns the database version
	int GetDatabaseVersion(void);

	// upgrades the database to a newer version
	// current version is the current version of the database
	void UpgradeDatabase( int currentVersion );

	IBPP::Database GetIBPPDB(void) {return db;};

	// creates and starts a transaction
	void TransactionStart( bool readOnly = false );
	// commit the transaction
	void TransactionCommit(void);
	// commit retaining
	void TransactionCommitRetain(void);
	// rolls back the transaction
	void TransactionRollback(void);
	// returns true if the transaction is started
	bool TransactionIsOpened(void);
	// returns a reference to the transaction
	IBPP::Transaction& TransactionGetReference(void) {return tr;}

	// creates a new firebird database on disk by restoring a backup
	// backupName is the name of the backup file that will be restored
	// databaseName is name of the disk file that will contain the database
	static void CreateDatabaseOnDisk( wxString serverName, wxString userName, wxString password, wxString backupName, wxString databaseName );


protected:

	wxString serverName, databaseName, userName, password;
	IBPP::Database db;
	IBPP::Transaction tr;
};


#endif
