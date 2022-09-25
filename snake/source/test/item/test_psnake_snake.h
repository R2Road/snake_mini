#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace test_psnake_snake
{
	class Declaration : public r2cm::iItem, public r2cm::SingleTon<Declaration>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Add_Remove : public r2cm::iItem, public r2cm::SingleTon<Add_Remove>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}