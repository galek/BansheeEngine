#pragma once

#include "BsPrerequisites.h"

namespace BansheeEngine
{
	class BS_EXPORT GUIArea
	{
	public:
		/**
		 * @brief	Sets up a new GUI area. All the layouts used in the area will be placed
		 * 			within the specified bounds.
		 * 			
		 *			If you want the area to expand vertically or horizontally, together with its parent
		 *			widget, set height or width to 0, respectively.
		 */
		static GUIArea* create(GUIWidget& widget, UINT32 x, UINT32 y, UINT32 width = 0, UINT32 height = 0, UINT32 depth = 0);
		static void destroy(GUIArea* area);

		GUILayout& getLayout() const { return *mLayout; }

		UINT32 getDepth() const { return mDepth; }
		void setDepth(UINT32 depth) { mDepth = depth; }

	private:
		friend class GUIWidget;

		GUIWidget& mWidget;
		UINT32 mX, mY, mWidth, mHeight;
		UINT32 mDepth;
		bool resizeWidthWithWindow, resizeHeightWithWindow;

		GUILayout* mLayout;

		GUIArea(GUIWidget& widget, UINT32 x, UINT32 y, UINT32 width, UINT32 height, UINT32 depth);
		~GUIArea();

		void notifyWindowResized(UINT32 newWidth, UINT32 newHeight);

		static void destroyInternal(GUIArea* area);
	};
}