/////////////////////////////////////////////////////////////////////////////
// Name:        dlg_file_information.cpp
// Purpose:     
// Author:      
// Modified by: 
// Created:     13/10/2011 10:24:01
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "dlg_file_information.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
#include "wx/mstream.h"
#include "wx/imaglist.h"
////@end includes

#include "dlg_file_information.h"
#include "paths.h"
#include "files.h"
#include "virtual_files.h"
#include "virtual_paths.h"
#include "audio_metadata.h"

#include <vector>

////@begin XPM images
////@end XPM images


/*!
 * CFileInformationDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( CFileInformationDialog, wxDialog )


/*!
 * CFileInformationDialog event table definition
 */

BEGIN_EVENT_TABLE( CFileInformationDialog, wxDialog )

////@begin CFileInformationDialog event table entries
    EVT_INIT_DIALOG( CFileInformationDialog::OnInitDialog )
    EVT_SIZE( CFileInformationDialog::OnSize )
    EVT_BUTTON( wxID_OK, CFileInformationDialog::OnOkClick )
    EVT_BUTTON( wxID_HELP, CFileInformationDialog::OnHelpClick )
////@end CFileInformationDialog event table entries

END_EVENT_TABLE()


/*!
 * CFileInformationDialog constructors
 */

CFileInformationDialog::CFileInformationDialog()
{
    Init();
}

CFileInformationDialog::CFileInformationDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * CFileInformationDialog creator
 */

bool CFileInformationDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin CFileInformationDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end CFileInformationDialog creation

	m_WindowPosition.SetWindow( this );
	m_WindowPosition.RestorePosition();
	
	return true;
}


/*!
 * CFileInformationDialog destructor
 */

CFileInformationDialog::~CFileInformationDialog()
{
////@begin CFileInformationDialog destruction
////@end CFileInformationDialog destruction

	m_WindowPosition.SavePosition();
}


/*!
 * Member initialisation
 */

void CFileInformationDialog::Init()
{
////@begin CFileInformationDialog member initialisation
    m_ListCtrl = NULL;
    m_TextCtrl = NULL;
////@end CFileInformationDialog member initialisation

	m_ItemData = NULL;
}


/*!
 * Control creation for CFileInformationDialog
 */

void CFileInformationDialog::CreateControls()
{    
////@begin CFileInformationDialog content construction
    CFileInformationDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_ListCtrl = new wxListCtrl( itemDialog1, ID_LISTCTRL1, wxDefaultPosition, wxSize(400, 200), wxLC_REPORT|wxSUNKEN_BORDER );
    itemBoxSizer2->Add(m_ListCtrl, 3, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText4 = new wxStaticText( itemDialog1, wxID_STATIC, _("Description:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText4, 0, wxALIGN_LEFT|wxALL, 5);

    m_TextCtrl = new wxTextCtrl( itemDialog1, ID_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
    itemBoxSizer2->Add(m_TextCtrl, 1, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer6 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer6, 0, wxGROW|wxALL, 10);
    wxButton* itemButton7 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer6->AddButton(itemButton7);

    wxButton* itemButton8 = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer6->AddButton(itemButton8);

    wxButton* itemButton9 = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer6->AddButton(itemButton9);

    itemStdDialogButtonSizer6->Realize();

////@end CFileInformationDialog content construction
}


/*!
 * wxEVT_SIZE event handler for ID_CFILEINFORMATIONDIALOG
 */

void CFileInformationDialog::OnSize( wxSizeEvent& event )
{
	event.Skip();
	ResizeLCColumns();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void CFileInformationDialog::OnOkClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK in CFileInformationDialog.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK in CFileInformationDialog. 
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void CFileInformationDialog::OnHelpClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP in CFileInformationDialog.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP in CFileInformationDialog. 
}


/*!
 * Should we show tooltips?
 */

bool CFileInformationDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap CFileInformationDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin CFileInformationDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end CFileInformationDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon CFileInformationDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin CFileInformationDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end CFileInformationDialog icon retrieval
}

void CFileInformationDialog::CreateLCHeaders() {
	wxListItem itemCol;
	int i = 0;

	itemCol.SetText( _("Name") );
	itemCol.SetAlign( wxLIST_FORMAT_LEFT );
	m_ListCtrl->InsertColumn( i++, itemCol );

	itemCol.SetText( _("Value") );
	itemCol.SetAlign( wxLIST_FORMAT_LEFT );
	m_ListCtrl->InsertColumn( i++, itemCol );
}

int CFileInformationDialog::AddLCRow( wxString col0, wxString col1 ) 
{
	wxListItem item;
	item.SetMask( wxLIST_MASK_STATE|wxLIST_MASK_TEXT|wxLIST_MASK_WIDTH );
	int i = m_ListCtrl->InsertItem( item );
	m_ListCtrl->SetItem( i, 0, col0 );
	m_ListCtrl->SetItem( i, 1, col1 );
	return i;
}

void CFileInformationDialog::ResizeLCColumns() {
	int x, y;
	int firstColumnWidth = 120;

	m_ListCtrl->GetClientSize( &x, &y );
	m_ListCtrl->SetColumnWidth( 0, firstColumnWidth );
	m_ListCtrl->SetColumnWidth( 1, x - firstColumnWidth - 2 );
}

void CFileInformationDialog::SetDescription( const wxString& descr ) {
	m_TextCtrl->SetValue( descr );
}

wxString CFileInformationDialog::GetDescription( void ) {
	return m_TextCtrl->GetValue();
}

void CFileInformationDialog::ShowFileData()
{
	wxASSERT( m_ItemData != NULL );
	m_ListCtrl->DeleteAllItems();

	// each row is inserted at the top, so we add them in reverse order

	wxString s;

	if( CAudioMetadata::IsAudioExtension(m_ItemData->GetExt()) ) {
		if( m_ItemData->GetChannels() == 0 ) s = wxEmptyString; else s = CUtils::long2string(m_ItemData->GetChannels());
		AddLCRow( _("Channels"), s );
		if( m_ItemData->GetSamplerate() == 0 ) s = wxEmptyString; else s = CUtils::long2string(m_ItemData->GetSamplerate());
		AddLCRow( _("Sample rate"), s );
		if( m_ItemData->GetBitrate() == 0 ) s = wxEmptyString; else s = CUtils::long2string(m_ItemData->GetBitrate());
		AddLCRow( _("Bitrate"), s );
		AddLCRow( _("Length"), CUtils::ConvertSecondsToTimeString(m_ItemData->GetLength()) );
		AddLCRow( _("Genre"), m_ItemData->GetGenre() );
		if( m_ItemData->GetNumber() == 0 ) s = wxEmptyString; else s = CUtils::long2string(m_ItemData->GetNumber());
		AddLCRow( _("Number"), s );
		AddLCRow( _("Comment"), m_ItemData->GetComment() );
		if( m_ItemData->GetYear() == 0 ) s = wxEmptyString; else s = CUtils::long2string(m_ItemData->GetYear());
		AddLCRow( _("Year"), s );
		AddLCRow( _("Title"), m_ItemData->GetTitle() );
		AddLCRow( _("Album"), m_ItemData->GetAlbum() );
		AddLCRow( _("Artist"), m_ItemData->GetArtist() );

		AddLCRow( wxEmptyString, wxEmptyString );
	}

	AddLCRow( _("File date"), m_ItemData->GetDateTime().FormatDate() + wxT(" ") + m_ItemData->GetDateTime().FormatTime() );
	AddLCRow( _("File size"), CUtils::HumanReadableFileSize(m_ItemData->GetSize()) + wxT(" (") + m_ItemData->GetSize().ToString() + wxT(" ") + _("bytes") + wxT(")") );
	AddLCRow( _("File name"), m_ItemData->GetName() );

	AddLCRow( wxEmptyString, wxEmptyString );

	long id;
	std::vector<long> idList = CVirtualFiles::ListVirtualPathIDs( m_ItemData->GetPhysicalFileID() );
	for( size_t k = 0; k < idList.size(); k++ ) {
		id = idList[k];;
		AddLCRow( _("Virtual path"), CVirtualPaths::GetFullPath(id) );
	}

	id = CFiles::GetPathID( m_ItemData->GetPhysicalFileID() );
	AddLCRow( _("Physical path"), CPaths::GetFullPath(id) );
}



/*!
 * wxEVT_INIT_DIALOG event handler for ID_CFILEINFORMATIONDIALOG
 */

void CFileInformationDialog::OnInitDialog( wxInitDialogEvent& event )
{
	CreateLCHeaders();
	ShowFileData();

	ResizeLCColumns();

    m_TextCtrl->SetFocus();
}

