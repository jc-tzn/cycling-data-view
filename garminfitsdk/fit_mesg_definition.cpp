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


#include <ostream>
#include "fit_mesg_definition.hpp"

namespace fit
{

MesgDefinition::MesgDefinition(void)
: num(FIT_MESG_NUM_INVALID), localNum(0), fields()
{
}

MesgDefinition::MesgDefinition(const Mesg& mesg)
: num(mesg.GetNum()), localNum(mesg.GetLocalNum())
{
   for (int i=0; i<mesg.GetNumFields(); i++)
      fields.push_back(FieldDefinition(mesg.GetFieldByIndex(i)));
}

FIT_UINT16 MesgDefinition::GetNum() const
{
   return num;
}

FIT_UINT8 MesgDefinition::GetLocalNum() const
{
   return localNum;
}

void MesgDefinition::SetNum(const FIT_UINT16 newNum)
{
   num = newNum;
}

void MesgDefinition::SetLocalNum(const FIT_UINT8 newLocalNum)
{
   localNum = newLocalNum;
}

void MesgDefinition::AddField(const FieldDefinition& fieldDef)
{
   fields.push_back(fieldDef);
}

void MesgDefinition::ClearFields()
{
   fields.clear();
}

int MesgDefinition::GetNumFields() const
{
   return ((int) fields.size());
}

std::vector<FieldDefinition>& MesgDefinition::GetFields()
{
   return fields;
}

FieldDefinition* MesgDefinition::GetField(const FIT_UINT8 fieldNum)
{
   for (int i=0; i<(int)fields.size(); i++)
   {
      if (fieldNum == fields[i].GetNum())
         return &(fields[i]);
   }

   return FIT_NULL;
}

FieldDefinition* MesgDefinition::GetFieldByIndex(const FIT_UINT16 index)
{
   if (index < fields.size())
      return &(fields[index]);

   return FIT_NULL;
}

const std::vector<FieldDefinition>& MesgDefinition::GetFields() const
{
   return fields;
}

const FieldDefinition* MesgDefinition::GetField(const FIT_UINT8 fieldNum) const
{
   for (int i=0; i<(int)fields.size(); i++)
   {
      if (fieldNum == fields[i].GetNum())
         return &(fields[i]);
   }

   return FIT_NULL;
}

const FieldDefinition* MesgDefinition::GetFieldByIndex(const FIT_UINT16 index) const
{
   if (index < fields.size())
      return &(fields[index]);

   return FIT_NULL;
}

FIT_BOOL MesgDefinition::operator==(const MesgDefinition& mesgDef) const
{
   if (num != mesgDef.num)
      return FIT_FALSE;

   if (localNum != mesgDef.localNum)
      return FIT_FALSE;

   if (fields.size() != mesgDef.fields.size())
      return FIT_FALSE;

   for (int i=0; i<(int)fields.size(); i++)
   {
      if (fields[i] != mesgDef.fields[i])
         return FIT_FALSE;
   }

   return FIT_TRUE;
}

FIT_BOOL MesgDefinition::operator!=(const MesgDefinition& mesgDef) const
{
   return !(*this == mesgDef);
}

FIT_BOOL MesgDefinition::Supports(const Mesg& mesg) const
{
   return Supports(MesgDefinition(mesg));
}

FIT_BOOL MesgDefinition::Supports(const MesgDefinition& mesgDef) const
{
   if (num != mesgDef.num)
      return FIT_FALSE;

   if (localNum != mesgDef.localNum)
      return FIT_FALSE;

   for (int i=0; i<(int)mesgDef.fields.size(); i++)
   {
      const FieldDefinition* supportedFieldDef = GetField(mesgDef.fields[i].GetNum());

      if (supportedFieldDef == FIT_NULL)  // Could not find field with matching number.
         return FIT_FALSE;

      if (mesgDef.fields[i].GetSize() > supportedFieldDef->GetSize())   // Other field definition is larger than this field definition.
         return FIT_FALSE;
   }

   return FIT_TRUE;
}

int MesgDefinition::Write(std::ostream &file) const
{
   int mesgSize = 6;

   file.put((FIT_HDR_TYPE_DEF_BIT) | (localNum & FIT_HDR_TYPE_MASK));   // Message definition record header with local message number.
   file.put(0); // Reserved
   file.put(GetArch());
   file.put((FIT_UINT8)num);
   file.put((FIT_UINT8)(num >> 8));
   file.put((FIT_UINT8)fields.size());

   for (FIT_UINT8 i=0; i<fields.size(); i++)
   {
      int fieldSize = fields[i].Write(file);

      if (fieldSize == 0)
         return 0;

      mesgSize += fieldSize;
   }

   return mesgSize;
}

} // namespace fit
