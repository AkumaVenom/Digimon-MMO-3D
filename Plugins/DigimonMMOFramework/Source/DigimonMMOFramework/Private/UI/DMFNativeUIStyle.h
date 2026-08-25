#pragma once

#include "CoreMinimal.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"
#include "Components/SlateWrapperTypes.h"
#include "Brushes/SlateColorBrush.h"

namespace DMFNativeUI
{
    inline FLinearColor Backdrop()      { return FLinearColor(0.005f, 0.012f, 0.028f, 0.78f); }
    inline FLinearColor Panel()         { return FLinearColor(0.018f, 0.040f, 0.075f, 0.97f); }
    inline FLinearColor PanelRaised()   { return FLinearColor(0.030f, 0.065f, 0.115f, 0.98f); }
    inline FLinearColor PanelSoft()     { return FLinearColor(0.040f, 0.085f, 0.145f, 0.88f); }
    inline FLinearColor SlotEmpty()     { return FLinearColor(0.018f, 0.050f, 0.105f, 0.92f); }
    inline FLinearColor Accent()        { return FLinearColor(0.00f, 0.78f, 0.95f, 1.00f); }
    inline FLinearColor AccentSoft()    { return FLinearColor(0.00f, 0.36f, 0.58f, 1.00f); }
    inline FLinearColor Gold()          { return FLinearColor(1.00f, 0.78f, 0.18f, 1.00f); }
    inline FLinearColor Text()          { return FLinearColor(0.93f, 0.97f, 1.00f, 1.00f); }
    inline FLinearColor Muted()         { return FLinearColor(0.58f, 0.68f, 0.78f, 1.00f); }
    inline FLinearColor Success()       { return FLinearColor(0.20f, 0.90f, 0.55f, 1.00f); }
    inline FLinearColor Danger()        { return FLinearColor(1.00f, 0.28f, 0.32f, 1.00f); }
    inline FLinearColor Disabled()      { return FLinearColor(0.20f, 0.25f, 0.31f, 0.85f); }


    inline FSlateChildSize FillSize(const float Value = 1.0f)
    {
        FSlateChildSize Result;
        Result.Value = Value;
        Result.SizeRule = ESlateSizeRule::Fill;
        return Result;
    }

    inline void StyleText(UTextBlock* TextBlock, const int32 Size, const FLinearColor& Color = Text(), const bool bBold = false)
    {
        if (!TextBlock)
        {
            return;
        }
        FSlateFontInfo FontInfo = TextBlock->GetFont();
        FontInfo.Size = Size;
        FontInfo.TypefaceFontName = bBold ? FName(TEXT("Bold")) : FName(TEXT("Regular"));
        TextBlock->SetFont(FontInfo);
        TextBlock->SetColorAndOpacity(FSlateColor(Color));
        TextBlock->SetShadowColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 0.75f));
        TextBlock->SetShadowOffset(FVector2D(1.0f, 1.0f));
    }

    inline FButtonStyle MakeButtonStyle(const bool bPrimary = false, const bool bDanger = false, const bool bSelected = false)
    {
        const FLinearColor NormalColor = bSelected
            ? FLinearColor(0.00f, 0.34f, 0.55f, 1.0f)
            : (bPrimary ? FLinearColor(0.00f, 0.27f, 0.45f, 1.0f) : FLinearColor(0.035f, 0.085f, 0.145f, 1.0f));
        const FLinearColor HoverColor = bDanger
            ? FLinearColor(0.55f, 0.08f, 0.10f, 1.0f)
            : (bPrimary ? FLinearColor(0.00f, 0.43f, 0.62f, 1.0f) : FLinearColor(0.06f, 0.16f, 0.25f, 1.0f));
        const FLinearColor PressedColor = bDanger
            ? FLinearColor(0.42f, 0.04f, 0.06f, 1.0f)
            : FLinearColor(0.00f, 0.23f, 0.36f, 1.0f);
        const FLinearColor DisabledColor = Disabled();

        FButtonStyle ButtonStyle;
        ButtonStyle.SetNormal(FSlateColorBrush(NormalColor));
        ButtonStyle.SetHovered(FSlateColorBrush(HoverColor));
        ButtonStyle.SetPressed(FSlateColorBrush(PressedColor));
        ButtonStyle.SetDisabled(FSlateColorBrush(DisabledColor));
        ButtonStyle.SetNormalPadding(FMargin(10.0f, 7.0f));
        ButtonStyle.SetPressedPadding(FMargin(11.0f, 8.0f, 9.0f, 6.0f));
        return ButtonStyle;
    }

    inline void StyleButton(UButton* Button, const bool bPrimary = false, const bool bDanger = false, const bool bSelected = false)
    {
        if (Button)
        {
            Button->SetStyle(MakeButtonStyle(bPrimary, bDanger, bSelected));
        }
    }

    inline void StyleInput(UEditableTextBox* Input)
    {
        if (!Input)
        {
            return;
        }
        const FLinearColor InputTextColor(0.05f, 0.08f, 0.12f, 1.0f);
        FEditableTextBoxStyle InputStyle = Input->GetWidgetStyle();
        FSlateFontInfo FontInfo = InputStyle.TextStyle.Font;
        FontInfo.Size = 16;
        InputStyle.SetFont(FontInfo);
        InputStyle.SetForegroundColor(FSlateColor(InputTextColor));
        InputStyle.SetFocusedForegroundColor(FSlateColor(InputTextColor));
        InputStyle.SetReadOnlyForegroundColor(FSlateColor(FLinearColor(0.22f, 0.25f, 0.30f, 1.0f)));
        InputStyle.SetBackgroundImageNormal(FSlateColorBrush(FLinearColor(0.86f, 0.90f, 0.94f, 1.0f)));
        InputStyle.SetBackgroundImageHovered(FSlateColorBrush(FLinearColor(0.92f, 0.95f, 0.98f, 1.0f)));
        InputStyle.SetBackgroundImageFocused(FSlateColorBrush(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f)));
        InputStyle.SetBackgroundImageReadOnly(FSlateColorBrush(FLinearColor(0.55f, 0.58f, 0.62f, 1.0f)));
        InputStyle.SetPadding(FMargin(12.0f, 9.0f));
        Input->SetWidgetStyle(InputStyle);
        Input->SetForegroundColor(InputTextColor);
    }

    inline void StylePanel(UBorder* Border, const FLinearColor& Color = Panel(), const FMargin Padding = FMargin(16.0f))
    {
        if (!Border)
        {
            return;
        }
        Border->SetBrushColor(Color);
        Border->SetPadding(Padding);
        Border->SetHorizontalAlignment(HAlign_Fill);
        Border->SetVerticalAlignment(VAlign_Fill);
    }
}
