#include "Utility/DMFCredentialUtility.h"
#include "Misc/SecureHash.h"
#include "Containers/StringConv.h"

FString UDMFCredentialUtility::HashCredential(const FString& PlainText)
{
    FTCHARToUTF8 Utf8(*PlainText);
    const FSHAHash Hash = FSHA1::HashBuffer(Utf8.Get(), static_cast<uint64>(Utf8.Length()));
    return Hash.ToString().ToLower();
}

bool UDMFCredentialUtility::IsValidUsername(const FString& Username)
{
    if (Username.Len() < 3 || Username.Len() > 24)
    {
        return false;
    }

    for (const TCHAR Character : Username)
    {
        if (!FChar::IsAlnum(Character) && Character != TEXT('_') && Character != TEXT('-'))
        {
            return false;
        }
    }

    return true;
}
