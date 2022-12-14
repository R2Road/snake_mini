#include "psm_scene_CompanyScene.h"

#include <conio.h>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2component_LabelSComponent.h"
#include "r2bix/r2component_TextureRenderComponent.h"
#include "r2bix/r2node_LabelSNode.h"

namespace psm_scene
{
	CompanyScene::CompanyScene( r2base::Director& director, psm::GameCoreUp&& game_core ) : r2node::SceneNode( director )
		, mGameCore( std::move( game_core ) )
	{}

	r2node::SceneNodeUp CompanyScene::Create( r2base::Director& director, psm::GameCoreUp&& game_core )
	{
		r2node::SceneNodeUp ret( new ( std::nothrow ) CompanyScene( director, std::move( game_core ) ) );
		if( !ret || !ret->Init() )
		{
			ret.reset();
		}

		return ret;
	}

	bool CompanyScene::Init()
	{
		if( !r2base::Node::Init() )
		{
			return false;
		}

		{
			auto node = AddChild<r2node::LabelSNode>();

			node->mTransformComponent->SetPosition(
				mDirector.GetScreenBufferSize().GetWidth() * 0.5f
				, mDirector.GetScreenBufferSize().GetHeight() * 0.5f
			);

			node->GetComponent<r2component::LabelSComponent>()->SetString( "Snake" );
		}

		return true;
	}
	void CompanyScene::Update( const float delta_time )
	{
		if( _kbhit() )
		{
			auto input = _getch();
			if( 27 == input )
			{
				mDirector.RequestAbort();
			}
		}

		r2node::SceneNode::Update( delta_time );
	}
}