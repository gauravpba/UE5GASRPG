// Copyright Gaurav Prativadi


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* _WidgetController)
{
	WidgetController = _WidgetController;
	WidgetControllerSet();
}
