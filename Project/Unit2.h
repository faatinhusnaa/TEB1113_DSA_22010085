//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <vector>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.ScrollBox.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Input;
	TEdit *Search;
	TLabel *SearchLabel;
	TLabel *InputLabel;
	TButton *Button1;
	TListBox *DataBox;
	TButton *SearchButton;
	TMemo *ResultBox;
	TLabel *Z;
	TLayout *Layout1;
	TSpeedButton *MenuButton;
	TPopup *MenuPopup;
	TListBox *MenuList;
	TMemo *LinearInfo;
	TMemo *BinaryInfo;
	TMemo *GroupInfo;
	TListBoxItem *GroupItem;
	TListBoxItem *BinaryItem;
	TListBoxItem *LinearItem;
	TListBoxItem *ExitMenuItem;
	TScrollBox *LinearBoxLayout;
	TScrollBox *BinaryBoxLayout;
	TLabel *Label1;
	TLabel *LinearSearchLabel;
	TLabel *BinarySearchLabel;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DataBoxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item);
	void __fastcall InputKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall SearchButtonClick(TObject *Sender);
	void __fastcall MenuButtonClick(TObject *Sender);
    void __fastcall ExitMenuItemClick(TObject *Sender);
	void __fastcall MenuItemClick(TObject *Sender);
	void __fastcall BinaryItemClick(TObject *Sender);
	void __fastcall LinearItemClick(TObject *Sender);
	void __fastcall GroupItemClick(TObject *Sender);

private:
void __fastcall ShowSearchBoxes(TScrollBox* scrollBox, const std::vector<String>& items, const String& keyword);	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
