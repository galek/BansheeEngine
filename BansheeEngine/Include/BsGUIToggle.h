#pragma once

#include "BsPrerequisites.h"
#include "BsGUIElement.h"
#include "BsGUIToggleGroup.h"
#include "BsImageSprite.h"
#include "boost/signal.hpp"

namespace BansheeEngine
{
	class BS_EXPORT GUIToggle : public GUIElement
	{
	public:
		static const CM::String& getGUITypeName();

		static GUIToggle* create(GUIWidget& parent, const CM::WString& text, const GUIElementStyle* style = nullptr);
		static GUIToggle* create(GUIWidget& parent, const GUILayoutOptions& layoutOptions, const CM::WString& text, const GUIElementStyle* style = nullptr);
	
		static GUIToggle* create(GUIWidget& parent, const CM::WString& text, std::shared_ptr<GUIToggleGroup> toggleGroup, const GUIElementStyle* style = nullptr);
		static GUIToggle* create(GUIWidget& parent, const GUILayoutOptions& layoutOptions, const CM::WString& text, std::shared_ptr<GUIToggleGroup> toggleGroup, const GUIElementStyle* style = nullptr);

		static std::shared_ptr<GUIToggleGroup> createToggleGroup();

		void toggleOn();
		void toggleOff();

		void _setToggleGroup(std::shared_ptr<GUIToggleGroup> toggleGroup);

		boost::signal<void(bool)> onToggled;
	protected:
		virtual ~GUIToggle();

		/**
		 * @copydoc GUIElement::getNumRenderElements()
		 */
		virtual CM::UINT32 getNumRenderElements() const;

		/**
		 * @copydoc GUIElement::getMaterial()
		 */
		virtual const CM::HMaterial& getMaterial(CM::UINT32 renderElementIdx) const;

		/**
		 * @copydoc GUIElement::getNumQuads()
		 */
		virtual CM::UINT32 getNumQuads(CM::UINT32 renderElementIdx) const;

		/**
		 * @copydoc GUIElement::fillBuffer()
		 */
		virtual void fillBuffer(CM::UINT8* vertices, CM::UINT8* uv, CM::UINT32* indices, CM::UINT32 startingQuad, 
			CM::UINT32 maxNumQuads, CM::UINT32 vertexStride, CM::UINT32 indexStride, CM::UINT32 renderElementIdx) const;

		/**
		 * @copydoc GUIElement::updateRenderElementsInternal()
		 */
		virtual void updateRenderElementsInternal();

		/**
		 * @copydoc GUIElement::updateBounds()
		 */
		virtual void updateBounds();

		virtual CM::UINT32 _getOptimalWidth() const;
		virtual CM::UINT32 _getOptimalHeight() const;

		virtual CM::UINT32 _getRenderElementDepth(CM::UINT32 renderElementIdx) const;
	protected:
		GUIToggle(GUIWidget& parent, const GUIElementStyle* style, const CM::WString& text, std::shared_ptr<GUIToggleGroup> toggleGroup, const GUILayoutOptions& layoutOptions);

		virtual bool mouseEvent(const GUIMouseEvent& ev);

	private:
		std::shared_ptr<GUIToggleGroup> mToggleGroup;
		ImageSprite* mImageSprite;
		TextSprite* mTextSprite;
		CM::UINT32 mNumImageRenderElements;
		bool mIsToggled;

		IMAGE_SPRITE_DESC mImageDesc;
		CM::WString mText;
	};
}