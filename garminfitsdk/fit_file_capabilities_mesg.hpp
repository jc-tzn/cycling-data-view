////////////////////////////////////////////////////////////////////////////////
// The following FIT Protocol software provided may be used with FIT protocol
// devices only and remains the copyrighted property of Dynastream Innovations Inc.
// The software is being provided on an "as-is" basis and as an accommodation,
// and therefore all warranties, representations, or guarantees of any kind
// (whether express, implied or statutory) including, without limitation,
// warranties of merchantability, non-infringement, or fitness for a particular
// purpose, are specifically disclaimed.
//
// Copyright 2008 Dynastream Innovations Inc.
////////////////////////////////////////////////////////////////////////////////
// ****WARNING****  This file is auto-generated!  Do NOT edit this file.
// Profile Version = 1.50Release
// Tag = $Name: AKW1_500 $
////////////////////////////////////////////////////////////////////////////////


#if !defined(FIT_FILE_CAPABILITIES_MESG_HPP)
#define FIT_FILE_CAPABILITIES_MESG_HPP

#include "fit_mesg.hpp"

namespace fit
{

class FileCapabilitiesMesg : public Mesg
{
   public:
      FileCapabilitiesMesg(void) : Mesg(Profile::MESG_FILE_CAPABILITIES)
      {
      }

      FileCapabilitiesMesg(const Mesg &mesg) : Mesg(mesg)
      {
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns message_index field
      ///////////////////////////////////////////////////////////////////////
      FIT_MESSAGE_INDEX GetMessageIndex(void) const
      {
         return GetFieldUINT16Value(254, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set message_index field
      ///////////////////////////////////////////////////////////////////////
      void SetMessageIndex(FIT_MESSAGE_INDEX messageIndex)
      {
         SetFieldUINT16Value(254, messageIndex, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns type field
      ///////////////////////////////////////////////////////////////////////
      FIT_FILE GetType(void) const
      {
         return GetFieldENUMValue(0, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set type field
      ///////////////////////////////////////////////////////////////////////
      void SetType(FIT_FILE type)
      {
         SetFieldENUMValue(0, type, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns flags field
      ///////////////////////////////////////////////////////////////////////
      FIT_FILE_FLAGS GetFlags(void) const
      {
         return GetFieldUINT8ZValue(1, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set flags field
      ///////////////////////////////////////////////////////////////////////
      void SetFlags(FIT_FILE_FLAGS flags)
      {
         SetFieldUINT8ZValue(1, flags, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns directory field
      ///////////////////////////////////////////////////////////////////////
      FIT_WSTRING GetDirectory(void) const
      {
         return GetFieldSTRINGValue(2, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set directory field
      ///////////////////////////////////////////////////////////////////////
      void SetDirectory(FIT_WSTRING directory)
      {
         SetFieldSTRINGValue(2, directory, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns max_count field
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetMaxCount(void) const
      {
         return GetFieldUINT16Value(3, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set max_count field
      ///////////////////////////////////////////////////////////////////////
      void SetMaxCount(FIT_UINT16 maxCount)
      {
         SetFieldUINT16Value(3, maxCount, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns max_size field
      // Units: bytes
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT32 GetMaxSize(void) const
      {
         return GetFieldUINT32Value(4, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set max_size field
      // Units: bytes
      ///////////////////////////////////////////////////////////////////////
      void SetMaxSize(FIT_UINT32 maxSize)
      {
         SetFieldUINT32Value(4, maxSize, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns checksum field
      ///////////////////////////////////////////////////////////////////////
      FIT_CHECKSUM GetChecksum(void) const
      {
         return GetFieldUINT8Value(252, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set checksum field
      ///////////////////////////////////////////////////////////////////////
      void SetChecksum(FIT_CHECKSUM checksum)
      {
         SetFieldUINT8Value(252, checksum, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

};

} // namespace fit

#endif // !defined(FIT_FILE_CAPABILITIES_MESG_HPP)
