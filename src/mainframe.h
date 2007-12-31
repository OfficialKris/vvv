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

/////////////////////////////////////////////////////////////////////////////
// Name:        mainframe.h
// Purpose:     
// Author:      
// Modified by: 
// Created:     29/12/2006 12:41:00
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 29/12/2006 12:41:00

#ifndef _MAINFRAME_H_
#define _MAINFRAME_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "mainframe.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/frame.h"
#include "wx/toolbar.h"
#include "wx/statusbr.h"
#include "wx/splitter.h"
#include "wx/treectrl.h"
#include "wx/listctrl.h"
////@end includes

#include "wx/docview.h"
#include <wx/arrstr.h>

#include "data_interface/volumes.h"
#include "data_interface/paths.h"
#include "data_interface/files.h"
#include "data_interface/virtual_paths.h"
#include "data_interface/virtual_files.h"
#include "data_interface/files_audio_metadata.h"
#include "choose_virtual_folder.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxMenu;
class wxStatusBar;
////@end forward declarations

class CRightPaneList;

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_MAIN_FRAME 10003
#define ID_TOOLBAR1 10004
#define ID_CATALOG_VOLUME 10005
#define ID_UP_ONE_FOLDER 10006
#define ID_VIEW_PHYSICAL 10011
#define ID_VIEW_VIRTUAL 10012
#define ID_VIEW_SEARCH 10013
#define ID_ADD_VIRTUAL_FOLDER 10015
#define ID_EDIT_RENAME 10073
#define ID_EDIT_DELETE 10074
#define ID_EDIT_OBJECT_DESCRIPTION 10018
#define ID_NEW_VIRTUAL_ROOT_FOLDER 10021
#define ID_NEW_VIRTUAL_SUBFOLDER 10022
#define ID_VIEW_TOOLBAR 10042
#define ID_VIEW_STATUS_BAR 10043
#define ID_HELP_CONTENTS 10072
#define ID_STATUSBAR1 10044
#define ID_SPLITTERWINDOW1 10045
#define ID_TREE_CONTROL 10046
#define ID_LIST_CONTROL 10047
#define SYMBOL_CMAINFRAME_STYLE wxDEFAULT_FRAME_STYLE|wxCAPTION
#define SYMBOL_CMAINFRAME_TITLE _("VVV")
#define SYMBOL_CMAINFRAME_IDNAME ID_MAIN_FRAME
#define SYMBOL_CMAINFRAME_SIZE wxSize(400, 300)
#define SYMBOL_CMAINFRAME_POSITION wxDefaultPosition
#define SYMBOL_CRIGHTPANELIST_STYLE wxLC_REPORT|wxNO_BORDER
#define SYMBOL_CRIGHTPANELIST_IDNAME ID_LIST_CONTROL
#define SYMBOL_CRIGHTPANELIST_SIZE wxSize(100, 100)
#define SYMBOL_CRIGHTPANELIST_POSITION wxDefaultPosition
////@end control identifiers

// virtual view
#define ID_TREE_CONTROL_VIRTUAL 10007

// search view
#define ID_SEARCH_PANEL 10031
#define ID_RADIOBOX_FILENAME 10037
#define ID_SEARCH_FILE_NAME 10032
#define ID_SEARCH_EXTENSION 10033
#define ID_RADIOBOX_SEARCH 10034
#define ID_BUTTON_SEARCH 10035
#define ID_RADIOBOX_DESCRIPTION 10040
#define ID_SEARCH_DESCRIPTION 10041

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

// number of base columns in the physical view
#define N_BASE_COLS_PHYSICAL 5
// number of columns in the virtual and search view
#define N_BASE_COLS_VIRTUAL 6
#define N_AUDIO_METADATA_COLUMNS 11

/*!
 * CMainFrame class declaration
 */

class CMainFrame: public wxFrame
{    
	friend class CRightPaneList;
	
	DECLARE_CLASS( CMainFrame )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    CMainFrame( );
    CMainFrame( wxWindow* parent, wxWindowID id = SYMBOL_CMAINFRAME_IDNAME, const wxString& caption = SYMBOL_CMAINFRAME_TITLE, const wxPoint& pos = SYMBOL_CMAINFRAME_POSITION, const wxSize& size = SYMBOL_CMAINFRAME_SIZE, long style = SYMBOL_CMAINFRAME_STYLE );

	virtual ~CMainFrame();

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_CMAINFRAME_IDNAME, const wxString& caption = SYMBOL_CMAINFRAME_TITLE, const wxPoint& pos = SYMBOL_CMAINFRAME_POSITION, const wxSize& size = SYMBOL_CMAINFRAME_SIZE, long style = SYMBOL_CMAINFRAME_STYLE );

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin CMainFrame event handler declarations

    /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_NEW
    void OnNEWClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_OPEN
    void OnOPENClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_EXIT
    void OnEXITClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_ADD_VIRTUAL_FOLDER
    void OnAddVirtualFolderClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_ADD_VIRTUAL_FOLDER
    void OnAddVirtualFolderUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_EDIT_RENAME
    void OnEditRenameClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_EDIT_RENAME
    void OnEditRenameUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_EDIT_DELETE
    void OnEditDeleteClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_EDIT_DELETE
    void OnEditDeleteUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_EDIT_OBJECT_DESCRIPTION
    void OnEditObjectDescriptionClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_EDIT_OBJECT_DESCRIPTION
    void OnEditObjectDescriptionUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_NEW_VIRTUAL_ROOT_FOLDER
    void OnNewVirtualRootFolderClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_NEW_VIRTUAL_ROOT_FOLDER
    void OnNewVirtualRootFolderUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_NEW_VIRTUAL_SUBFOLDER
    void OnNewVirtualSubfolderClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_NEW_VIRTUAL_SUBFOLDER
    void OnNewVirtualSubfolderUpdate( wxUpdateUIEvent& event );

#if defined(__WXMAC__)
    /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_PREFERENCES
    void OnPreferencesClick( wxCommandEvent& event );

#endif
    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_CATALOG_VOLUME
    void OnCatalogVolumeClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_CATALOG_VOLUME
    void OnCatalogVolumeUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_VIEW_PHYSICAL
    void OnViewPhysicalClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_VIEW_PHYSICAL
    void OnViewPhysicalUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_VIEW_VIRTUAL
    void OnViewVirtualClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_VIEW_VIRTUAL
    void OnViewVirtualUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_VIEW_SEARCH
    void OnViewSearchClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_VIEW_SEARCH
    void OnViewSearchUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_UP_ONE_FOLDER
    void OnUpOneFolderClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_UP_ONE_FOLDER
    void OnUpOneFolderUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_VIEW_TOOLBAR
    void OnViewToolbarClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_VIEW_STATUS_BAR
    void OnViewStatusBarClick( wxCommandEvent& event );

#if defined(__WXMSW__) || defined(__WXGTK__)
    /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_PREFERENCES
    void OnPreferencesClick( wxCommandEvent& event );

#endif
    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_HELP_CONTENTS
    void OnHelpContentsClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_ABOUT
    void OnABOUTClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_TREE_SEL_CHANGED event handler for ID_TREE_CONTROL
    void OnTreeControlSelChanged( wxTreeEvent& event );

    /// wxEVT_COMMAND_TREE_ITEM_EXPANDING event handler for ID_TREE_CONTROL
    void OnTreeControlItemExpanding( wxTreeEvent& event );

    /// wxEVT_COMMAND_TREE_ITEM_MENU event handler for ID_TREE_CONTROL
    void OnTreeControlItemMenu( wxTreeEvent& event );

////@end CMainFrame event handler declarations

    void OnListControlColLeftClick( wxListEvent& event );
    void OnListControlItemActivated( wxListEvent& event );
    void OnListControlSetFocus( wxFocusEvent& event );
    void OnListControlContextMenu( wxContextMenuEvent& event );
    void OnListControlKillFocus( wxFocusEvent& event );


////@begin CMainFrame member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end CMainFrame member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin CMainFrame member variables
    wxToolBar* m_Toolbar;
    wxMenu* m_fileMenu;
    wxStatusBar* m_StatusBar;
////@end CMainFrame member variables

	// search panel member variables
    wxPanel* m_SearchPanel;
    wxRadioBox* m_FilenameRadioBox;
    wxTextCtrl* m_SearchFileName;
    wxTextCtrl* m_SearchExtension;
    wxRadioBox* m_SearchRadioBox;
    wxButton* m_SearchButton;
    wxRadioBox* m_DescriptionRadioBox;
    wxTextCtrl* m_SearchDescription;

    /// wxEVT_COMMAND_TREE_ITEM_EXPANDING event handler for ID_TREE_CONTROL_VIRTUAL
    void OnTreeControlVirtualItemExpanding( wxTreeEvent& event );

    /// wxEVT_COMMAND_TREE_SEL_CHANGED event handler for ID_TREE_CONTROL_VIRTUAL
    void OnTreeControlVirtualSelChanged( wxTreeEvent& event );

	/// wxEVT_COMMAND_TREE_ITEM_MENU event handler for ID_TREE_CONTROL_VIRTUAL
    void OnTreeControlVirtualItemMenu( wxTreeEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SEARCH
    void OnButtonSearchClick( wxCommandEvent& event );

	// creates a new virtual folder from user input
	// FatherID is the primary key of the father of this folder in the database: it can be NULL for root folders
	// windowTitle is the title of the window that will ask for the new folder's name
	void CreateNewVirtualFolder( CNullableLong FatherID, wxString windowTitle );

	// called when the user chooses a file from the MRU list
	void OnMRUFile( wxCommandEvent& event );

	// creates the volume label for a tree control
	wxString CreateVolumeLabel( const wxString& VolumeName, const wxString& VolumeDescription );

	// formats an object decription for display in the listview
	wxString FormatObjectDescriptionForListView( const wxString& ObjectDescription );

	// audio metadata columns
	enum AMDColumns {
		amdArtist = 0,
		amdAlbum,
		amdTitle,
		amdYear,
		amdComment,
		amdNumber,
		amdGenre,
		amdLength,
		amdBitrate,
		amdSampleRate,
		amdChannels
	};

private:

	// the possible views available in the program
	enum CurrentView {
		cvPhysical,
		cvVirtual,
		cvSearch
	};
	// holds the current view
	CurrentView m_CurrentView;

	// true if the listview has the focus
	bool m_ListViewHasFocus;

	// true if we are popping up a context menu from the list control
	// we need this because popping up a menu causes a listcontrol lostfocus event in wxGTK that would
	// set m_ListViewHasFocus = 0 causing wrong behaviours
	bool m_PoppingUpContextMenu;

	// possible choices for file name search
	enum FilenameSearchKind {
		fskIsEqual = 0,
		fskStartsWith,
		fskContains
	};

	// possible search choices
	enum SearchScope {
		ssAllPhysicalVolumes = 0,
		ssSelectedPhysicalFolder,
		ssSelectedVirtualFolder
	};

	// values for the Status bar elements
	enum StatusBarElements {
		sbeMenuDescription = 0,
		sbeObjectsNumber,
		sbeObjectsSize
	};

	// each element of the array is true id the corresponding audio metadata column must be shown
	// it is false if the column must be hidden
	bool *m_amdColumnsToShow;

	// true if the list control is showing audio metadata, false otherwise
	bool m_CurrentlyShowingAudioMetadata;

	// number and total size of the files shown in each view
	long nPhysicalFiles, nVirtualFiles, nSearchFiles;
	wxLongLong sizePhysicalFiles, sizeVirtualFiles, sizeSearchFiles;

	// struct to hold data for database server connection
	struct CDBConnectionData {
		bool connectToServer;	// true of we want to connect to a server
		wxString serverName;
		wxString userName;
		wxString password;
		bool IsLocalhost() { return (serverName == "localhost") || (serverName == "127.0.0.1"); }
	} DBConnectionData;

	// minimum duration of a task (in seconds) before playing a beep at task end
	int m_BeepTime;

	// pointers to some windows used in the main frame
	CRightPaneList* m_listCtl;	// the list control
	wxTreeCtrl* m_treePhysicalCtl;	// the tree control with the physical view
	wxTreeCtrl* m_treeVirtualCtl;		// the tree control with the virtual view
	wxSplitterWindow* m_splitterWindow;	// the splitter window

	// accessors for the above windows
	CRightPaneList* GetListControl() { return m_listCtl; }
	wxTreeCtrl* GetTreePhysicalControl() { return m_treePhysicalCtl; }
	wxTreeCtrl* GetTreeVirtualControl() { return m_treeVirtualCtl; }
	wxSplitterWindow* GetSplitterWindow() { return m_splitterWindow; }

	// true if we want to reopen the last used catalog at startup
	bool m_reopenLastUsedCatalog;

	// fills the physical tree control
	void LoadTreeControl(void);
	// loads a volume and its folders in the tree control
	void LoadVolumeInTreeControl( CVolumes vol, wxTreeCtrl* tctl, wxTreeItemId rootID);
	// loads a folder in the tree control, adding its subfolder to be able to show the "+" near folders with subfolders
	void LoadFolderInTreeControl( long VolumeID, wxTreeCtrl* tctl, wxTreeItemId fatherTreeID, long fatherID);

	// fills the virtual tree control
	void LoadVirtualTreeControl(void);
	void LoadVirtualFolderInTreeControl( wxTreeCtrl* tctl, wxTreeItemId fatherTreeID, long fatherID);

	// create the headers for the list control in report mode
	void CreateListControlHeaders(void);

	// adds the audio metadata columns to the list control
	void CreateAudioMetadataListControlHeaders( void );

	// deletes the audio metadata columns from the list control
	void DeleteAudioMetadataListControlHeaders( void );

	// used to handle the list of recently opened files
	wxFileHistory* m_fileHistory;

	// used to save the selected folder in the @Add to virtual folder@ dialog box
	wxArrayString m_SelectedVirtualFolderForAdd;

	// opens a database
	// expectedVersion is the database version that the program is designed to use
	// if the database version is lower it will upgrade the database
	void OpenDatabase( wxString fileName, int expectedVersion );

	// width of the listview columns in physical view
	int m_ListviewColWidthPhysical[N_BASE_COLS_PHYSICAL + N_AUDIO_METADATA_COLUMNS];
	// width of the listview columns in virtual view
	int m_ListviewColWidthVirtual[N_BASE_COLS_VIRTUAL + N_AUDIO_METADATA_COLUMNS];

	// stores the column widths of the list control columns in physical view
	void StoreListControlPhysicalWidth();
	// stores the column widths of the list control columns in virtual view
	void StoreListControlVirtualWidth();

	// shows the physical view
	void ShowPhysicalView(void);
	// shows the virtual view
	void ShowVirtualView(void);
	// shows the search view
	void ShowSearchView(void);
	// hides the physical view
	void HidePhysicalView(void);
	// hides the virtual view
	void HideVirtualView(void);
	// hides the search view
	void HideSearchView(void);
	// redraws the current view (conceptually equivalent to switching to another view and back to the original)
	void RefreshCurrentView(void);

	// searches a physical folder for files, appends them to the list control, then recursion
	void SearchPhysicalFolder( wxString fileName, bool useFileNameWildcards, wxString ext, wxString description, bool useDescriptionWildcards, long folderID, long volumeID );

	// searches a virtual folder for files, appends them to the list control, then recursion
	void SearchVirtualFolder( wxString fileName, bool useFileNameWildcards, wxString ext, wxString description, bool useDescriptionWildcards, long folderID );

	// adds a row to the listview in Virtual or Search mode
	// return the index position of the newly inserted row
	// fileID contains the primary key of the current row: it may be the physical or virtual file id, depnding on the current view
	// physicalFileID is always the ID od the FILES table
	int AddRowToVirtualListControl( wxListCtrl* lctl, bool isFolder, wxString fileName, wxLongLong fileSize, wxString ext, wxDateTime dateTime, wxString physicalPath, long fileID, long virtualPathFileID, wxString fileDescription, long physicalFileID );

	// updates the content of the status bar: it does not use the first element because it is used by the menu/toolbar
	void UpdateStatusBar( long nObjects, wxLongLong sizeObjects );

	// adds the audio metadata to the current listview row
	void AddAudioMetatataToListControl( CFilesAudioMetadata fam, wxListCtrl *lctl, int itemIndex, int firstColumnIndex );

	// receives as input the number of a visible column and returns the number that the same column would have
	// if no columns were hidden
	int ColumnNumIfNoColumnsHidden( int inColNum );

	// deletes the currently selected virtual folder
	void DeleteSelectedVirtualFolder();

	// deletes the currently selected volume
	void DeleteSelectedVolume();

	// renames the currently selected volume
	void RenameSelectedVolume();

	// renames the currently selected virtual folder
	void RenameSelectedVirtualFolder();

	// returns true if the Edit/Rename command must be enabled
	bool IsEditRenameEnabled();

	// returns true if the Edit/Delete command must be enabled
	bool IsEditDeleteEnabled();

	// deletes the virtual file(s) currently selected in the list control
	void DeleteSelectedVirtualFiles();

	// returns true if only virtual files are selected in the listview (no virtual folders)
	bool AreOnlyVirtualFilesSelected();

protected:
	// shows in the listview the files contained in the passed folder
	void ShowFolderFiles( wxTreeItemId itemID );
	// shows in the listview the files contained in the currently selected folder
	void ShowSelectedFolderFiles(void );

	// shows in the listview the files contained in the passed virtual folder
	void ShowVirtualFolderFiles( wxTreeItemId itemID );
	// shows in the listview the files contained in the currently selected virtual folder
	void ShowSelectedVirtualFolderFiles(void);

	// deletes all the list control items
	void DeleteAllListControlItems(void);
};

/*!
 * CRightPaneList class declaration
 */

class CRightPaneList: public wxListCtrl
{    
    DECLARE_CLASS( CRightPaneList )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    CRightPaneList();
    CRightPaneList(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxLC_ICON, const wxValidator& validator = wxDefaultValidator);

    /// Creation
    bool Create(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxLC_ICON, const wxValidator& validator = wxDefaultValidator);

    /// Destructor
    ~CRightPaneList();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin CRightPaneList event handler declarations

    /// wxEVT_COMMAND_LIST_ITEM_ACTIVATED event handler for ID_LIST_CONTROL
    void OnListControlItemActivated( wxListEvent& event );

    /// wxEVT_COMMAND_LIST_COL_CLICK event handler for ID_LIST_CONTROL
    void OnListControlColLeftClick( wxListEvent& event );

    /// wxEVT_CONTEXT_MENU event handler for ID_LIST_CONTROL
    void OnListControlContextMenu( wxContextMenuEvent& event );

    /// wxEVT_SET_FOCUS event handler for ID_LIST_CONTROL
    void OnListControlSetFocus( wxFocusEvent& event );

    /// wxEVT_KILL_FOCUS event handler for ID_LIST_CONTROL
    void OnListControlKillFocus( wxFocusEvent& event );

////@end CRightPaneList event handler declarations

////@begin CRightPaneList member function declarations

////@end CRightPaneList member function declarations

////@begin CRightPaneList member variables
////@end CRightPaneList member variables

	// stores a reference to the main frame object, needed to call mainframe's member functions
	void SetMainFrame( CMainFrame* mfp ) { m_MainFrame = mfp; }

private:

	CMainFrame* m_MainFrame;
};

#endif
    // _MAINFRAME_H_
