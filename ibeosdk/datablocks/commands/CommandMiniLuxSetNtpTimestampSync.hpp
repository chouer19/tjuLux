//======================================================================
/*! \file CommandMiniLuxSetNtpTimestampSync.hpp
 *
 * \copydoc Copyright
 * \author Jan Christian Dittmer (jcd)
 * \date Apr 13, 2015
 *///-------------------------------------------------------------------
#ifndef IBEOSDK_COMMANDMINILUXSETNTPTIMESTAMPSYNC_HPP_SEEN
#define IBEOSDK_COMMANDMINILUXSETNTPTIMESTAMPSYNC_HPP_SEEN

//======================================================================

#include <ibeosdk/misc/WinCompatibility.hpp>

#include <ibeosdk/datablocks/commands/Command.hpp>
#include <ibeosdk/datablocks/DataBlock.hpp>
#include <ibeosdk/misc/ParameterIndex.hpp>
#include <ibeosdk/misc/ParameterData.hpp>
#include <ibeosdk/Time.hpp>
#include <ibeosdk/inttypes.hpp>
#include <ibeosdk/DataTypeId.hpp>

//======================================================================

namespace ibeosdk {

//======================================================================

class CommandMiniLuxSetNtpTimestampSync : public ibeosdk::MiniLuxCommand<CommandId::CmdLuxSetNTPTimestampSync>,
                                          public ibeosdk::DataBlock {
public:
	//========================================
	/*!\brief Length of the LuxSetNtpTimestampSync command.
	 *///-------------------------------------
	static const int commandSize = 14;

public:
	CommandMiniLuxSetNtpTimestampSync(const NTPTime timestamp);

public:
	//========================================
	/*!\brief Get the DataType of this DataBlock.
	 * \return Always DataType#DataType_Command.
	 *///-------------------------------------
	virtual DataTypeId getDataType() const { return dataType; }

	//========================================
	/*!\brief Get the size of the serialization.
	 * \return Number of bytes used by the serialization
	 *         of this Command.
	 *///-------------------------------------
	virtual std::streamsize getSerializedSize() const { return std::streamsize(commandSize); }

	//========================================
	/*!\brief Deserialize data from the given stream \a is into
	 *        this CommandSetFilter.
	 * \param[in, out] is  Stream that provides the serialized
	 *                     data to fill this CommandSetFilter.
	 *                     On exit the \a is get pointer will
	 *                     be behind the read data.
	 * \param[in]      dh  IbeoDataHeader that has been received
	 *                     together with the serialized data in \a is.
	 * \return Whether the operation was successful.
	 * \retval true Everything is alright, no error occured.
	 * \retval false Reading the data from the stream has failed.
	 *///-------------------------------------
	virtual bool deserialize(std::istream& is, const IbeoDataHeader& dh);

	//========================================
	/*!\brief Serialize data into the given stream \a os.
	 * \param[out] os  Stream that receive the serialized
	 *                 data from this CommandSetFilter.
	 * \return Whether the operation was successful.
	 * \retval true Everything is alright, no error occured.
	 * \retval false Writing the data into the stream has failed.
	 *///-------------------------------------
	virtual bool serialize(std::ostream& os) const;

public:
	virtual bool callListener(DataListenerBase&) const { return false; }

public:
	virtual bool serializeToStream(std::ostream& os) const { return serialize(os); }
	virtual std::streamsize getCommandLength() const { return getSerializedSize(); }

protected:
	uint32_t m_reserved0;
	NTPTime m_timestamp;
}; // CommandMiniLuxSetNtpTimestampSync

//======================================================================

} // namespace ibeosdk

//======================================================================

#endif // IBEOSDK_COMMANDMINILUXSETNTPTIMESTAMPSYNC_HPP_SEEN

//======================================================================
