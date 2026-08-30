// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Data/DMFItemData.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFItemData_generated_h
#error "DMFItemData.generated.h already included, missing '#pragma once' in DMFItemData.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFItemData_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDMFItemData *************************************************************
struct Z_Construct_UClass_UDMFItemData_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFItemData(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFItemData_h_38_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFItemData_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFItemData(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFItemData, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFItemData) \
	DECLARE_SERIALIZER(UDMFItemData)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFItemData_h_38_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDMFItemData(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFItemData(UDMFItemData&&) = delete; \
	UDMFItemData(const UDMFItemData&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFItemData); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFItemData); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDMFItemData) \
	NO_API virtual ~UDMFItemData();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFItemData_h_35_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFItemData_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFItemData_h_38_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFItemData_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFItemData;

// ********** End Class UDMFItemData ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFItemData_h

// ********** Begin Enum EDMFItemCategory **********************************************************
#define FOREACH_ENUM_EDMFITEMCATEGORY(op) \
	op(EDMFItemCategory::Consumable) \
	op(EDMFItemCategory::Material) \
	op(EDMFItemCategory::KeyItem) \
	op(EDMFItemCategory::Quest) \
	op(EDMFItemCategory::Miscellaneous) 

enum class EDMFItemCategory : uint8;
template<> struct TIsUEnumClass<EDMFItemCategory> { enum { Value = true }; };
template<> UE_NODEBUG DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFItemCategory>();
// ********** End Enum EDMFItemCategory ************************************************************

// ********** Begin Enum EDMFItemUseEffect *********************************************************
#define FOREACH_ENUM_EDMFITEMUSEEFFECT(op) \
	op(EDMFItemUseEffect::None) \
	op(EDMFItemUseEffect::RestoreHP) \
	op(EDMFItemUseEffect::RestoreSP) 

enum class EDMFItemUseEffect : uint8;
template<> struct TIsUEnumClass<EDMFItemUseEffect> { enum { Value = true }; };
template<> UE_NODEBUG DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFItemUseEffect>();
// ********** End Enum EDMFItemUseEffect ***********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
