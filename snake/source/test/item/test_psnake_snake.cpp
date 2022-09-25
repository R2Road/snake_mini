#include "test_psnake_snake.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

#include "psnake/psnake_Snake.h"

namespace test_psnake_snake
{
	r2cm::iItem::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Snake : Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Declaration::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( psnake::Snake snake( 3, 7 ) );

			std::cout << r2cm::split;

			{
				EXPECT_EQ( 3, snake.GetWidth() );
				EXPECT_EQ( 7, snake.GetHeight() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, snake.GetMaxX() );
				EXPECT_EQ( 6, snake.GetMaxY() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( snake.GetWidth() * snake.GetHeight(), snake.Size() );
				OUTPUT_VALUE( snake.Size() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}