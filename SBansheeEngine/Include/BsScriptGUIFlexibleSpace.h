#pragma once

#include "BsScriptEnginePrerequisites.h"
#include "BsScriptObject.h"

namespace BansheeEngine
{
	class BS_SCR_BE_EXPORT ScriptGUIFlexibleSpace : public ScriptObject<ScriptGUIFlexibleSpace>
	{
	public:
		static void initMetaData();

	private:
		static void internal_createInstance(MonoObject* instance, MonoObject* parentLayout);
		static void internal_destroyInstance(ScriptGUIFlexibleSpace* nativeInstance);

		static void internal_destroy(ScriptGUIFlexibleSpace* nativeInstance);
		static void internal_disable(ScriptGUIFlexibleSpace* nativeInstance);
		static void internal_enable(ScriptGUIFlexibleSpace* nativeInstance);

		static void initRuntimeData();

		ScriptGUIFlexibleSpace(GUIFlexibleSpace& flexibleSpace, GUILayout* parentLayout);

		GUIFlexibleSpace& mFlexibleSpace;
		GUILayout* mParentLayout;
	};
}