#include "DbgEditorWidget1.h"
#include "BsEditorWindow.h"
#include "BsGUILabel.h"
#include "BsGUIButton.h"
#include "BsGUIInputBox.h"
#include "BsGUIScrollArea.h"
#include "BsGUIArea.h"
#include "BsGUILayout.h"
#include "BsEditorWindow.h"
#include "BsEditorWidgetContainer.h"

using namespace CamelotFramework;
using namespace BansheeEngine;

namespace BansheeEditor
{
	DbgEditorWidget1* DbgEditorWidget1::Instance = nullptr;

	DbgEditorWidget1::DbgEditorWidget1()
		:EditorWidget(L"DbgEditorWidget1")
	{
		
	}

	DbgEditorWidget1::~DbgEditorWidget1()
	{

	}

	void DbgEditorWidget1::initialize()
	{
		GUILayout& layout = mContent->getLayout();
		//
		//mDbgLabel = GUILabel::create(*mGUI, "Testing test");
		//layout.addElement(mDbgLabel);

		//layout.addElement(GUIInputBox::create(*mGUI));
		//layout.addElement(GUIInputBox::create(*mGUI, GUILayoutOptions::fixed(100, 100), true));

		GUIScrollArea* scrollArea = GUIScrollArea::create(getParentWidget());
		layout.addElement(scrollArea);

		GUILayout& scrollLayout = scrollArea->getLayout().addLayoutX();

		//scrollLayout.addElement(GUIButton::create(*mGUI, L"Test A"));
		//scrollLayout.addElement(GUIButton::create(*mGUI, L"Test B"));
		//scrollLayout.addElement(GUIButton::create(*mGUI, L"Test C"));
		//scrollLayout.addElement(GUIButton::create(*mGUI, L"Test D"));
		//scrollLayout.addElement(GUIButton::create(*mGUI, L"Test E"));
		//scrollLayout.addElement(GUIButton::create(*mGUI, L"Test F"));
		//scrollLayout.addElement(GUIButton::create(*mGUI, L"Test G"));
		//scrollLayout.addElement(GUIButton::create(*mGUI, L"Test H"));
		//scrollLayout.addElement(GUIButton::create(*mGUI, L"Test I"));
		//scrollLayout.addElement(GUIButton::create(*mGUI, L"Test J"));
		//scrollLayout.addElement(GUIButton::create(*mGUI, L"Test K"));
		//scrollLayout.addElement(GUIButton::create(*mGUI, L"Test L"));

		scrollLayout.addElement(GUIInputBox::create(getParentWidget(), GUILayoutOptions::fixed(100, 100), true));
		scrollLayout.addElement(GUIInputBox::create(getParentWidget(), GUILayoutOptions::fixed(100, 100), true));
		scrollLayout.addElement(GUIInputBox::create(getParentWidget(), GUILayoutOptions::fixed(100, 100), true));

		//GUIFlexibleSpace& space4 = otherLayout.addFlexibleSpace();
		//otherLayout.addElement(mDbgLabel);

		//GUIFixedSpace& space = otherLayout.addSpace(10); // Due to bug in MSVC compiler I need to store return value
		//GUIFlexibleSpace& space3 = otherLayout.addFlexibleSpace();
		//otherLayout.addElement(GUIWindowFrame::create(*mGUI, GUILayoutOptions::fixed(100, 100)));
		//GUIFixedSpace& space2 = otherLayout.addSpace(10);
		//otherLayout.addElement(GUIButton::create(*mGUI, "Test"));
		//otherLayout.addElement(GUIWindowFrame::create(*mGUI));

		//GUIArea* backgroundArea = GUIArea::create(*mGUI, 0, 0, 0, 0, 2000);
		//backgroundArea->getLayout().addElement(GUITexture::create(*mGUI, GUILayoutOptions::expandableXY(), GUIImageScaleMode::RepeatToFit, mGUI->getSkin()->getStyle("WindowBackground")));

		//GUIArea* windowFrameArea = GUIArea::create(*mGUI, 0, 0, 0, 0, 1999);
		//windowFrameArea->getLayout().addElement(GUIWindowFrame::create(*mGUI));

		//GUIArea* titleBarBackgroundArea = GUIArea::create(*mGUI, 0, 1, 0, 11, 1999);
		//titleBarBackgroundArea->getLayout().addSpace(1);
		//titleBarBackgroundArea->getLayout().addElement(GUITexture::create(*mGUI, GUIImageScaleMode::RepeatToFit, GUILayoutOptions::expandableXY(), mGUI->getGUISkin()->getStyle("TitleBarBg")));
		//titleBarBackgroundArea->getLayout().addSpace(1);

		//mRenderWindow->resize(300, 250);
		//mRenderWindow->setVisible(false);
	}

	DbgEditorWidget1* DbgEditorWidget1::instance()
	{
		return Instance;
	}

	DbgEditorWidget1* DbgEditorWidget1::open()
	{
		if(Instance != nullptr)
			return Instance;

		EditorWindow* newWindow = EditorWindow::create();

		DbgEditorWidget1* newWidget = new (cm_alloc<DbgEditorWidget1>()) DbgEditorWidget1();
		newWindow->widgets().add(*newWidget);
		newWidget->initialize();
		Instance = newWidget;

		return newWidget;
	}

	void DbgEditorWidget1::close()
	{
		if(Instance != nullptr)
		{
			Instance->mParent->_notifyWidgetDestroyed(Instance);

			EditorWidget::destroy(Instance);
		}
		
		Instance = nullptr; 
	}
}