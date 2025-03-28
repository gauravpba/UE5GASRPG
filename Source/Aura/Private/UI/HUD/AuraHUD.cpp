// Copyright Gaurav Prativadi


#include "UI/HUD/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& widgetControllerParams)
{
	if (OverlayWidgetController != nullptr) return OverlayWidgetController;
	
	OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
	OverlayWidgetController->SetWidgetControllerParams(widgetControllerParams);
	OverlayWidgetController->BindCallbacksToDependencies();
	
	return OverlayWidgetController;
	
}

UAttributeMenuWidgetController* AAuraHUD::GetAttributeMenuWidgetController(
	const FWidgetControllerParams& widgetControllerParams)
{
	if (AttributeMenuWidgetController != nullptr) return AttributeMenuWidgetController;

	AttributeMenuWidgetController = NewObject<UAttributeMenuWidgetController>(this, AttributeMenuWidgetControllerClass);
	AttributeMenuWidgetController->SetWidgetControllerParams(widgetControllerParams);
	AttributeMenuWidgetController->BindCallbacksToDependencies();
	
	return AttributeMenuWidgetController;
	
}

void AAuraHUD::InitOverlay(APlayerController* playerController, APlayerState* playerState,
                           UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet)
{

	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class Uninitialized. Please fill out BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class Uninitialized. Please fill out BP_AuraHUD"));

	
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);

	const FWidgetControllerParams widgetControllerParams(playerController, playerState, AbilitySystemComponent, AttributeSet);

	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(widgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	
	Widget->AddToViewport();
	
}
