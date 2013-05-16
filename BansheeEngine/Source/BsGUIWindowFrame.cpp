#include "BsGUIWindowFrame.h"
#include "BsImageSprite.h"
#include "BsGUIWidget.h"
#include "BsGUISkin.h"
#include "BsSpriteTexture.h"
#include "BsGUILayoutOptions.h"
#include "CmTexture.h"

using namespace CamelotFramework;

namespace BansheeEngine
{
	const String& GUIWindowFrame::getGUITypeName()
	{
		static String name = "WindowFrame";
		return name;
	}

	GUIWindowFrame::GUIWindowFrame(GUIWidget& parent, const GUI_LAYOUT_OPTIONS& layoutOptions)
		:GUIElement(parent, layoutOptions)
	{
		const GUISkin* skin = parent.getGUISkin();

		mStyle = skin->getStyle(getGUITypeName());
		mImageSprite = CM_NEW(ImageSprite, PoolAlloc) ImageSprite();

		mDesc.texture = mStyle->normal.texture;

		if(mDesc.texture != nullptr)
		{
			mDesc.width = mDesc.texture->getTexture()->getWidth();
			mDesc.height = mDesc.texture->getTexture()->getHeight();
		}

		mDesc.borderLeft = mStyle->border.left;
		mDesc.borderRight = mStyle->border.right;
		mDesc.borderTop = mStyle->border.top;
		mDesc.borderBottom = mStyle->border.bottom;
	}

	GUIWindowFrame::~GUIWindowFrame()
	{
		CM_DELETE(mImageSprite, ImageSprite, PoolAlloc);
	}

	GUIWindowFrame* GUIWindowFrame::create(GUIWidget& parent)
	{
		return CM_NEW(GUIWindowFrame, PoolAlloc) GUIWindowFrame(parent, getDefaultLayoutOptions());
	}

	GUIWindowFrame* GUIWindowFrame::create(GUIWidget& parent, const GUI_LAYOUT_OPTIONS& layoutOptions)
	{
		return CM_NEW(GUIWindowFrame, PoolAlloc) GUIWindowFrame(parent, layoutOptions);
	}

	UINT32 GUIWindowFrame::getNumRenderElements() const
	{
		return mImageSprite->getNumRenderElements();
	}

	const HMaterial& GUIWindowFrame::getMaterial(UINT32 renderElementIdx) const
	{
		return mImageSprite->getMaterial(renderElementIdx);
	}

	UINT32 GUIWindowFrame::getNumQuads(UINT32 renderElementIdx) const
	{
		return mImageSprite->getNumQuads(renderElementIdx);
	}

	void GUIWindowFrame::updateRenderElementsInternal()
	{		
		mImageSprite->update(mDesc);
		mBounds = mImageSprite->getBounds();
	}

	void GUIWindowFrame::fillBuffer(UINT8* vertices, UINT8* uv, UINT32* indices, UINT32 startingQuad, UINT32 maxNumQuads, 
		UINT32 vertexStride, UINT32 indexStride, UINT32 renderElementIdx) const
	{
		mImageSprite->fillBuffer(vertices, uv, indices, startingQuad, maxNumQuads, vertexStride, indexStride, renderElementIdx);
	}

	const GUI_LAYOUT_OPTIONS& GUIWindowFrame::getDefaultLayoutOptions()
	{
		static GUI_LAYOUT_OPTIONS layoutOptions;
		static bool layoutOptionsInitialized = false;

		if(!layoutOptionsInitialized)
		{
			layoutOptions.fixedWidth = false;
			layoutOptions.fixedHeight = false;

			layoutOptionsInitialized = true;
		}

		return layoutOptions;
	}
}