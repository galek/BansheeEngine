//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Marko Pintera (marko.pintera@gmail.com). All rights reserved. **********************//
#pragma once

#include "BsOAPrerequisites.h"
#include "BsOAFileReader.h"

namespace BansheeEngine
{
	/** @addtogroup OpenAudio
	 *  @{
	 */

	/** Used for reading .WAV audio files. */
	class OAWaveReader : public OAFileReader
	{
	public:
		OAWaveReader();

		/** @copydoc OAFileReader::open */
		bool open(const SPtr<DataStream>& stream, AudioFileInfo& info) override;

		/** @copydoc OAFileReader::read */
		UINT32 read(UINT8* samples, UINT32 numSamples) override;

		/** @copydoc OAFileReader::seek */
		void seek(UINT32 offset) override;

		/** @copydoc OAFileReader::isValid */
		bool isValid(const SPtr<DataStream>& stream) override;
	private:
		bool parseHeader(AudioFileInfo& info);

		SPtr<DataStream> mStream;
		UINT32 mDataOffset;
		UINT32 mBytesPerSample;

		static const UINT32 MAIN_CHUNK_SIZE = 12;
	};

	/** @} */
}