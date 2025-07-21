#include <fmx.h>
#pragma hdrstop

#include "Unit2.h"
#include <vector>
#include <algorithm>
#include <chrono>
#include <Fmx.Layouts.hpp>
#include <System.UITypes.hpp>
#include <FMX.Controls.hpp>
#include <cmath>

#pragma package(smart_init)
#pragma resource "*.fmx"

TForm2 *Form2;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	GroupItem->OnClick = MenuItemClick;
	BinaryItem->OnClick = MenuItemClick;
	LinearItem->OnClick = MenuItemClick;
}
//---------------------------------------------------------------

// Add item to DataBox
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	String datatext = Input->Text.Trim();
	if (datatext.IsEmpty()) {
		ShowMessage("Please enter data before adding.");
		return;
	}
	DataBox->Items->Add(datatext);
	Input->Text = "";
}
//---------------------------------------------------------------

// Handle Enter key press in Input box
void __fastcall TForm2::InputKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar, TShiftState Shift)
{
	if (Key == VK_RETURN && !Input->Text.IsEmpty()) {
		DataBox->Items->Add(Input->Text);
		Input->Text = "";
	}
}
//---------------------------------------------------------------

// Remove item from DataBox on click
void __fastcall TForm2::DataBoxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)
{
	int index = Item->Index;
	if (index >= 0 && index < DataBox->Items->Count) {
		DataBox->Items->Delete(index);
	}
}
//---------------------------------------------------------------

// Perform both linear and binary search and visualize results
void __fastcall TForm2::SearchButtonClick(TObject *Sender)
{

	String keyword = Search->Text.Trim();
	if (keyword.IsEmpty()) {
		ShowMessage("Please enter a value to search.");
		return;
	}

	ResultBox->Lines->Clear();

	// Linear Search
	ResultBox->Lines->Add("Linear Search Process:");
	ResultBox->Lines->Add("-----------------------");

	bool foundLinear = false;
	int linearIndex = -1, linearStepCount = 0;

	auto linearStart = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < DataBox->Items->Count; ++i) {
		String current = DataBox->Items->Strings[i];
		ResultBox->Lines->Add("Step " + IntToStr(i + 1) + ": Compare with \"" + current + "\"");
		linearStepCount++;

		if (current == keyword) {
			ResultBox->Lines->Add("Found at index " + IntToStr(i));
			linearIndex = i;
			foundLinear = true;
			break;
		}
	}

	auto linearEnd = std::chrono::high_resolution_clock::now();
	auto linearDuration = std::chrono::duration_cast<std::chrono::microseconds>(linearEnd - linearStart).count();

	if (!foundLinear)
		ResultBox->Lines->Add("Result: Not found in Linear Search.");
	else
		ResultBox->Lines->Add("Result: \"" + keyword + "\" found at index " + IntToStr(linearIndex));

	ResultBox->Lines->Add("Time Taken: " + IntToStr(linearDuration) + " μs");
	ResultBox->Lines->Add("Total Steps: " + IntToStr(linearStepCount));
	ResultBox->Lines->Add("");

	DataBox->ItemIndex = foundLinear ? linearIndex : -1;

	//---------------------------------------------------------------

	// Binary Search (on sorted copy)
	std::vector<String> originalItems;
	for (int i = 0; i < DataBox->Items->Count; ++i)
		originalItems.push_back(DataBox->Items->Strings[i]);

	std::vector<String> sortedItems = originalItems;
	std::sort(sortedItems.begin(), sortedItems.end(), [](const String &a, const String &b) {
		try {
			return a.ToInt() < b.ToInt();
		} catch (...) {
			return a < b;
		}
	});

	ResultBox->Lines->Add("Binary Search Process (on sorted data):");
	ResultBox->Lines->Add("---------------------------------------");

	String sortedStr = "Sorted data: [";
	for (size_t i = 0; i < sortedItems.size(); ++i) {
		sortedStr += "\"" + sortedItems[i] + "\"";
		if (i < sortedItems.size() - 1)
			sortedStr += ", ";
	}
	sortedStr += "]";
	ResultBox->Lines->Add(sortedStr);

	auto binaryStart = std::chrono::high_resolution_clock::now();

	int left = 0, right = sortedItems.size() - 1;
	bool foundBinary = false;
	int binaryIndex = -1, binaryStepCount = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		String midVal = sortedItems[mid];
		binaryStepCount++;

		ResultBox->Lines->Add("Step " + IntToStr(binaryStepCount) + ": Compare with \"" + midVal + "\" at index " + IntToStr(mid));

		if (midVal == keyword) {
			foundBinary = true;
			binaryIndex = mid;
			ResultBox->Lines->Add("Found at sorted index " + IntToStr(mid));
			break;
		}

		try {
			int midInt = midVal.ToInt();
			int keyInt = keyword.ToInt();

			if (midInt < keyInt)
				left = mid + 1;
			else
				right = mid - 1;
		} catch (...) {
			if (midVal < keyword)
				left = mid + 1;
			else
				right = mid - 1;
		}
	}

	auto binaryEnd = std::chrono::high_resolution_clock::now();
	auto binaryDuration = std::chrono::duration_cast<std::chrono::microseconds>(binaryEnd - binaryStart).count();

	if (!foundBinary)
		ResultBox->Lines->Add("Result: Not found in Binary Search.");
	else
		ResultBox->Lines->Add("Result: \"" + keyword + "\" found at sorted index " + IntToStr(binaryIndex));

	ResultBox->Lines->Add("Time Taken: " + IntToStr(binaryDuration) + " μs");
	ResultBox->Lines->Add("Total Steps: " + IntToStr(binaryStepCount));
	ResultBox->Lines->Add("");

	//---------------------------------------------------------------

	// Final Comparison
	ResultBox->Lines->Add("Comparison Summary:");
	ResultBox->Lines->Add("-------------------");
	ResultBox->Lines->Add("Linear Search : " + IntToStr(linearStepCount) + " steps | " + IntToStr(linearDuration) + " μs");
	ResultBox->Lines->Add("Binary Search : " + IntToStr(binaryStepCount) + " steps | " + IntToStr(binaryDuration) + " μs");

	if (linearDuration < binaryDuration)
		ResultBox->Lines->Add("-> Linear Search was faster (likely due to early match).");
	else if (linearDuration > binaryDuration)
		ResultBox->Lines->Add("-> Binary Search was faster (due to algorithm efficiency).");
	else
		ResultBox->Lines->Add("-> Both searches took the same time.");

	if (linearStepCount < binaryStepCount)
		ResultBox->Lines->Add("-> Linear Search used fewer steps.");
	else if (linearStepCount > binaryStepCount)
		ResultBox->Lines->Add("-> Binary Search used fewer steps.");
	else
		ResultBox->Lines->Add("-> Both used the same number of steps.");

	ResultBox->Lines->Add("Note: Fewer steps doesn't always mean faster speed.");
	ResultBox->Lines->Add("");

	// Time and Space Complexity
	ResultBox->Lines->Add("Time & Space Complexity:");
	ResultBox->Lines->Add("--------------------------");

	ResultBox->Lines->Add("Linear Search:");
	ResultBox->Lines->Add(" - Best Case    : O(1)");
	ResultBox->Lines->Add(" - Worst Case   : O(n)");
	ResultBox->Lines->Add(" - Average Case : O(n)");
	ResultBox->Lines->Add(" - Space        : O(1)");

	ResultBox->Lines->Add("");

	ResultBox->Lines->Add("Binary Search (on sorted copy):");
	ResultBox->Lines->Add(" - Best Case    : O(1)");
	ResultBox->Lines->Add(" - Worst Case   : O(log n)");
	ResultBox->Lines->Add(" - Average Case : O(log n)");
	ResultBox->Lines->Add(" - Space        : O(n) (due to copy + sort)");

//---------------------------------------------------------------
	ResultBox->Lines->Add("Estimated Theoretical Complexity:");
	ResultBox->Lines->Add("--------------------------");

   int n = DataBox->Items->Count; // total elements
   ResultBox->Lines->Add("Total Elements (n): " + IntToStr(n));
   ResultBox->Lines->Add("");

// Linear Search
ResultBox->Lines->Add("Linear Search:");
if (linearStepCount == 1) {
	ResultBox->Lines->Add(" - Time Complexity (Best Case): O(1)");
} else {
	ResultBox->Lines->Add(" - Time Complexity (Worst Case): O(n) → O(" + IntToStr(n) + ")");
}
ResultBox->Lines->Add(" - Steps Taken: " + IntToStr(linearStepCount));
ResultBox->Lines->Add(" - Space Complexity: O(1)");
ResultBox->Lines->Add("");

// Binary Search (on already sorted data)
ResultBox->Lines->Add("Binary Search (on sorted data):");
ResultBox->Lines->Add(" - Time Complexity: O(log n) ≈ O(" +
	FloatToStrF(log2(n), ffFixed, 4, 1) + ")");
ResultBox->Lines->Add(" - Steps Taken: " + IntToStr(binaryStepCount));
ResultBox->Lines->Add(" - Space Complexity: O(1)");

//---------------------------------------------------------------

	// Visual result boxes
	LinearBoxLayout->Visible = true;
	BinaryBoxLayout->Visible = true;

	ShowSearchBoxes(LinearBoxLayout, originalItems, keyword);
	ShowSearchBoxes(BinaryBoxLayout, sortedItems, keyword);
}
//---------------------------------------------------------------

// Menu popup show
void __fastcall TForm2::MenuButtonClick(TObject *Sender)
{
	TPointF position = MenuButton->LocalToAbsolute(PointF(0, MenuButton->Height));
	MenuPopup->PlacementTarget = MenuButton;
	MenuPopup->IsOpen = true;
}
//---------------------------------------------------------------

// Menu item click handler
void __fastcall TForm2::MenuItemClick(TObject *Sender)
{
	TListBoxItem* item = dynamic_cast<TListBoxItem*>(Sender);
	if (!item) return;

	GroupInfo->Visible = false;
	BinaryInfo->Visible = false;
	LinearInfo->Visible = false;

	if (item->Text == "Group Info") GroupInfo->Visible = true;
	else if (item->Text == "Binary Search") BinaryInfo->Visible = true;
	else if (item->Text == "Linear Search") LinearInfo->Visible = true;

	MenuPopup->IsOpen = false;
}
//---------------------------------------------------------------

void __fastcall TForm2::ExitMenuItemClick(TObject *Sender)
{
	MenuPopup->IsOpen = false;
	GroupInfo->Visible = false;
	BinaryInfo->Visible = false;
	LinearInfo->Visible = false;
}
//---------------------------------------------------------------

void __fastcall TForm2::BinaryItemClick(TObject *Sender)
{
 MenuItemClick(Sender);
}
//---------------------------------------------------------------
void __fastcall TForm2::LinearItemClick(TObject *Sender)
 {
 MenuItemClick(Sender);
 }
 //---------------------------------------------------------------
void __fastcall TForm2::GroupItemClick(TObject *Sender)
 {
 MenuItemClick(Sender);
 }
//---------------------------------------------------------------

// Create label boxes for search visualization
void __fastcall TForm2::ShowSearchBoxes(TScrollBox* scrollBox, const std::vector<String>& items, const String& keyword)
{
	int stepCount = items.size();
	scrollBox->BeginUpdate();

	// Clear previous children
	for (int i = scrollBox->Content->ChildrenCount - 1; i >= 0; --i) {
		TControl* control = dynamic_cast<TControl*>(scrollBox->Content->Children->Items[i]);
		if (control) {
			control->Parent = nullptr;
			delete control;
		}
	}

	// Add boxes
	float topOffset = 10;
	for (size_t i = 0; i < items.size(); ++i) {
		TRectangle* box = new TRectangle(scrollBox);
		box->Parent = scrollBox->Content;
		box->Width = scrollBox->Width - 20;
		box->Height = 40;
		box->Position->X = 10;
		box->Position->Y = topOffset;
		box->Margins->Rect = TRectF(5, 5, 5, 5);
		box->Fill->Color = TAlphaColorRec::Pink; // Pink box
		box->Stroke->Color = TAlphaColorRec::Black;
		box->Stroke->Thickness = 1;

		// Label
		TLabel* label = new TLabel(box);
		label->Parent = box;
		label->Align = TAlignLayout::Client;
		label->Margins->Rect = TRectF(5, 5, 5, 5);
		label->WordWrap = true;
		label->Text = items[i];
		label->TextSettings->HorzAlign = TTextAlign::Center;
		label->TextSettings->VertAlign = TTextAlign::Center;
		if (items[i] == keyword)
			label->TextSettings->FontColor = TAlphaColorRec::Red;

		topOffset += box->Height + 10;
	}

	scrollBox->EndUpdate();
	scrollBox->Visible = true;

}

//---------------------------------------------------------------
