#include <stdint.h>
#include <stdbool.h>
#include <gb/gb.h>

// ;)
#include "MLP.h"

const unsigned char ROM[] =
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // White
	0x00,0x00,0x42,0x42,0x66,0x66,0x7E,0x7E,0x5A,0x5A,0x7E,0x7E,0x3C,0x3C,0x00,0x00, // Cat head
	0x07,0x00,0x3F,0x00,0x7F,0x00,0xFF,0x00,0xFF,0x00,0x7F,0x00,0x1F,0x00,0x03,0x00, // Shadow
	0xE0,0x00,0xFC,0x00,0xFE,0x00,0xFF,0x00,0xFF,0x00,0xFE,0x00,0xF8,0x00,0xC0,0x00,
	0x00,0x00,0x0C,0x0C,0x0C,0x0C,0x0F,0x0F,0x0F,0x0C,0x0F,0x0F,0x0C,0x0C,0x0C,0x0C, // Kate
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xF8,0xF8,0x08,0xFC,0x04,0xCC,0xB4,0xFC,0x84,
	0x0E,0x0E,0x0E,0x0E,0x0F,0x0F,0x0F,0x0C,0x0F,0x0F,0x0C,0x0F,0xFD,0xFF,0xFC,0xFC,
	0xC6,0xBA,0xFE,0x82,0xC6,0x3A,0xFF,0x01,0xFF,0xFF,0x85,0xFF,0x4B,0xFF,0x85,0x85,
	0xFF,0xFF,0x40,0xFF,0xBF,0x60,0xDF,0x30,0xEF,0x18,0xF7,0x0C,0xFF,0xFF,0x00,0xFF, // Floor
	0xFF,0xFF,0x04,0xFF,0xFB,0x0C,0xF7,0x18,0xEF,0x30,0xDF,0x60,0xFF,0xFF,0x00,0xFF,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x7F,0x7F,0x8F,0x90,0x83,0x88,0x80,0xC4,0xC0,0xA2,0xC0,0x91,0xE0,0x89,0xC0,0x86, // Crate 1
	0xFE,0xFE,0xF1,0x09,0xC1,0x13,0x01,0x23,0x01,0x47,0x01,0x8B,0x05,0x13,0x01,0x23,
	0xF0,0x84,0xC0,0x88,0xC0,0x91,0xC0,0xA2,0x80,0xC4,0x83,0x88,0x80,0xBF,0x7F,0x7F,
	0x0D,0x63,0x01,0x93,0x01,0x8B,0x01,0x47,0x01,0x23,0xC1,0x13,0x03,0xFF,0xFE,0xFE,
	0x7F,0x7F,0xA0,0x80,0xD2,0xA1,0xA1,0x8E,0x88,0x90,0x80,0x90,0xA0,0x91,0x91,0xA2, // Crate 2
	0xFE,0xFE,0x05,0x01,0x4B,0x85,0x85,0x71,0x11,0x09,0x01,0x09,0x05,0x89,0x09,0x45,
	0x90,0xA2,0xA0,0x91,0x80,0x90,0x88,0x90,0xA1,0x8E,0xD2,0xA1,0xA0,0x80,0x7F,0x7F,
	0x89,0x45,0x05,0x89,0x01,0x09,0x11,0x09,0x85,0x71,0x4B,0x85,0x05,0x01,0xFE,0xFE,
	0x7F,0x7F,0x80,0x80,0xA8,0x81,0x88,0x81,0x90,0x82,0x90,0x82,0xA1,0x84,0xA1,0x84, // Crate 3
	0xFE,0xFE,0x01,0x01,0x15,0x81,0x11,0x81,0x09,0x41,0x09,0x41,0x85,0x21,0x85,0x21,
	0x81,0x88,0xA1,0x88,0x80,0x90,0x83,0x90,0x80,0xA0,0x80,0xBF,0x80,0x80,0x7F,0x7F,
	0x81,0x11,0x85,0x11,0x01,0x09,0xC1,0x09,0x01,0x05,0x01,0xFD,0x01,0x01,0xFE,0xFE,
	0x7F,0x7F,0x8F,0x90,0x80,0x80,0x80,0xC0,0xC0,0x80,0xC0,0x80,0xC0,0x81,0xC0,0x81, // Crate 4
	0xFE,0xFE,0xF1,0x09,0x01,0x03,0x01,0x03,0x01,0x03,0x01,0x03,0x01,0x03,0x01,0x03,
	0xC0,0x82,0xC0,0x83,0xC0,0x80,0xC0,0x80,0x80,0xC0,0x80,0x80,0x80,0xBF,0x7F,0x7F,
	0x01,0x43,0x01,0xC3,0x01,0x43,0x01,0x03,0x01,0x03,0x01,0x03,0x03,0xFF,0xFE,0xFE,
	0x7F,0x7F,0x8F,0x90,0x80,0x80,0x80,0xC0,0xC0,0x80,0xC0,0x80,0xC0,0x81,0xC0,0x81, // Crate 5
	0xFE,0xFE,0xF1,0x09,0x01,0x03,0x01,0x03,0x01,0x03,0x01,0x03,0x01,0xC3,0x01,0x03,
	0xC0,0x81,0xC0,0x80,0xC0,0x83,0xC0,0x80,0x80,0xC0,0x80,0x80,0x80,0xBF,0x7F,0x7F,
	0x01,0x83,0x01,0x43,0x01,0xC3,0x01,0x03,0x01,0x03,0x01,0x03,0x03,0xFF,0xFE,0xFE
};

typedef struct {
	uint8_t x;
	uint8_t y;
	uint8_t side;
	uint8_t holding;
} s_player;
const uint8_t playerYpos[] = {0x0, 0x3, 0x7, 0xB};

typedef struct {
	uint8_t levelNumber;
	uint8_t level[32];
	uint8_t levelThreshold;
	bool levelFinished;
	uint8_t moves;
	s_player player;
} s_gameState;

void draw_playfield( void );

void level_load( uint8_t number );
void level_display( void );
void level_update( void );
uint8_t level_check_status( void );


s_gameState g_game;

void main( void )
{
	// Don't mess while we configure stuff.
	disable_interrupts();
	DISPLAY_OFF;
	LCDC_REG |= 0x10; // BG at 0x8000
	
	// Set palettes
	BGP_REG		= 0xE4U;
	OBP0_REG	= 0xE4U;
	OBP1_REG	= 0xE4U;
	
	// Background
	SCX_REG = 0;
	SCY_REG = 0;
	set_bkg_data( 0, 32, ROM );
	
	// Sprite
	SPRITES_8x8;
	set_sprite_data( 0, 28, ROM );
	set_sprite_tile( 0, 4 );
	set_sprite_tile( 1, 5 );
	set_sprite_tile( 2, 6 );
	set_sprite_tile( 3, 7 );
	set_sprite_prop( 0, 0 );
	set_sprite_prop( 1, 0 );
	set_sprite_prop( 2, 0 );
	set_sprite_prop( 3, 0 );
	SHOW_SPRITES;
	
	SHOW_BKG;
	HIDE_WIN;
	
	// Release the hound
	DISPLAY_ON;
	enable_interrupts();
	
	// Init game state
	g_game.levelNumber = 0;
	g_game.level[0] = 0;
	g_game.levelThreshold = 0;
	g_game.levelFinished = false;
	g_game.moves = 0;
	g_game.player.x = 80+4;
	g_game.player.y = 0;
	g_game.player.side = 0;
	g_game.player.holding = 0;
	
	draw_playfield();
	level_load( 1 );
	
	// Main loop
	unsigned char mode = 3; //0: menu, 1: options, 2: audio test, 3: game
	
	unsigned char joystickState = 0;
	unsigned char joystickStatePrevious = 0;
	while(1)
	{
		wait_vbl_done();
		
		// Controls
		joystickStatePrevious = joystickState;
		joystickState = joypad();
		if( mode == 3 )
		{
			// (P^S) -> is the state the same ?
			// (P^S)&S -> is the touch pressed ?
			// (P^S)&P -> is the touch released ?
			const unsigned char joystickPressed = ((joystickStatePrevious ^ joystickState) & joystickState );
			
			if( joystickPressed & J_LEFT )
			{
				g_game.player.x = 80+4;
				g_game.player.side = 0;
				set_sprite_tile( 0, 4 );
				set_sprite_tile( 1, 5 );
				set_sprite_tile( 2, 6 );
				set_sprite_tile( 3, 7 );
				set_sprite_prop( 0, 0 );
				set_sprite_prop( 1, 0 );
				set_sprite_prop( 2, 0 );
				set_sprite_prop( 3, 0 );
			}
			if( joystickPressed & J_RIGHT )
			{
				g_game.player.x = 72+4;
				g_game.player.side = 1;
				set_sprite_tile( 0, 5 );
				set_sprite_tile( 1, 4 );
				set_sprite_tile( 2, 7 );
				set_sprite_tile( 3, 6 );
				set_sprite_prop( 0, S_FLIPX );
				set_sprite_prop( 1, S_FLIPX );
				set_sprite_prop( 2, S_FLIPX );
				set_sprite_prop( 3, S_FLIPX );
			}
			if( joystickPressed & J_UP )
			{
				if( g_game.player.y > 0 )
				{
					g_game.player.y -= 1;
				}else{
					g_game.player.y = 0;
				}
			}
			if( joystickPressed & J_DOWN )
			{
				if( g_game.player.y < 3 )
				{
					g_game.player.y += 1;
				}else{
					g_game.player.y = 3;
				}
			}
			
			if( joystickPressed & J_A )
			{
				bool change = false;
				// Calculat with row Kate is facing
				uint8_t row = 4*((g_game.player.y*2)+g_game.player.side);
				
				// Try to grab the crate
				if( g_game.player.holding == 0 )
				{
					// Look if there is a crate to take
					// (Yes, it's dirty and not universal. Remember I'm trying to make a game in 4h)
					if( g_game.level[row+3] != 0 )
					{
						g_game.player.holding = g_game.level[row+3];
						g_game.level[row+3] = 0;
						change = true;
						//play_SFX( sfx_grab );
					}else{
						if( g_game.level[row+2] != 0 )
						{
							g_game.player.holding = g_game.level[row+2];
							g_game.level[row+2] = 0;
							change = true;
							//play_SFX( sfx_grab );
						}else{
							if( g_game.level[row+1] != 0 )
							{
								g_game.player.holding = g_game.level[row+1];
								g_game.level[row+1] = 0;
								change = true;
								//play_SFX( sfx_grab );
							}else{
								if( g_game.level[row] != 0 )
								{
									g_game.player.holding = g_game.level[row];
									g_game.level[row] = 0;
									change = true;
									//play_SFX( sfx_grab );
								}else{
									//play_SFX( sfx_nope );
								}
							}
						}
					}
					
				// Try to put the crate
				}else{
					// Look if there is a space to put our crate to
					// (Yes, it's dirty and not universal. Remember I'm trying to make a game in 4h)
					if( g_game.level[row] == 0 )
					{
						g_game.level[row] = g_game.player.holding;
						g_game.player.holding = 0;
						change = true;
						//play_SFX( sfx_put );
					}else{
						if( g_game.level[row+1] == 0 )
						{
							g_game.level[row+1] = g_game.player.holding;
							g_game.player.holding = 0;
							change = true;
							//play_SFX( sfx_put );
						}else{
							if( g_game.level[row+2] == 0 )
							{
								g_game.level[row+2] = g_game.player.holding;
								g_game.player.holding = 0;
								change = true;
								//play_SFX( sfx_put );
							}else{
								if( g_game.level[row+3] == 0 )
								{
									g_game.level[row+3] = g_game.player.holding;
									g_game.player.holding = 0;
									change = true;
									//play_SFX( sfx_put );
								}else{
									//play_SFX( sfx_nope );
								}
							}
						}
					}
				}
				/*
				g_game.player.holding++;
				//play_SFX( sfx_sweep_up );
				if( g_game.player.holding > 5 )
				{
					g_game.player.holding = 0;
				}
				*/
				if( change )
				{
					uint8_t tmp = g_game.player.holding*4;
					set_sprite_tile( 4, 8+tmp );
					set_sprite_tile( 5, 9+tmp );
					set_sprite_tile( 6, 10+tmp );
					set_sprite_tile( 7, 11+tmp );
					
					level_update();
					level_display();
					
					level_check_status();
				}
			}
			
			//*
			if( joystickPressed & J_B )
			{
				if( g_game.levelFinished )
				{
					if( g_game.levelNumber < 250 )
					{
						level_load( g_game.levelNumber+1 );
						//play_music( msk_playing );
					}
				}
				
				//play_SFX( sfx_sweep_down );
			}
			//*/
			
			// Update player display
			uint8_t X = g_game.player.x;
			uint8_t Y = 18+(32*g_game.player.y);
			move_sprite( 0, X,Y );
			move_sprite( 1, X+8,Y );
			move_sprite( 2, X,Y+8 );
			move_sprite( 3, X+8,Y+8 );
			
			if( g_game.player.holding != 0 )
			{
				int8_t o = g_game.player.side==0?-12:12;
				move_sprite( 4, X+o,Y-2 );
				move_sprite( 5, X+o+8,Y-2 );
				move_sprite( 6, X+o,Y+6 );
				move_sprite( 7, X+o+8,Y+6 );
			}else{
				move_sprite( 4, 0,0 );
				move_sprite( 5, 0,0 );
				move_sprite( 6, 0,0 );
				move_sprite( 7, 0,0 );
			}
			
			if( g_game.levelFinished )
			{
				//play_music( msk_finished );
			}
		}
		
	}
}


/*
 * Loads a level
 */
void level_load( uint8_t number )
{
	g_game.levelNumber = number;
	
	//TODO make a generator like:
	// 7-6th bits -> is number of type of crates-1 (0->1 crate type, 4->5 crates type)
	// 5-0th bits -> number of switches
	
	// Hardcoded for now to test
	//  0 4
	//  8 12
	// 16 20
	// 24 28
	g_game.levelFinished = false;
	for( uint8_t i=0; i<32; i++)
	{
		g_game.level[i] = 0;
	}
	switch( number )
	{
		case 1 :
		{
			g_game.level[19] = 1;
			g_game.level[22] = 1;
			
			g_game.levelThreshold = 2;
			g_game.player.y = 2;
			break;
		}
		
		case 2 :
		{
			g_game.level[20] = 2;
			g_game.level[24] = 1;
			g_game.level[25] = 2;
			g_game.level[28] = 1;
			
			g_game.levelThreshold = 2;
			g_game.player.y = 2;
			break;
		}
		
		case 3 :
		{
			g_game.level[12] = 1;
			g_game.level[20] = 1;
			g_game.level[21] = 2;
			g_game.level[22] = 1;
			g_game.level[24] = 1;
			g_game.level[25] = 2;
			
			g_game.levelThreshold = 2;
			g_game.player.y = 3;
			break;
		}
		
		case 4 :
		{
			g_game.level[0] = 1;
			g_game.level[1] = 2;
			g_game.level[2] = 1;
			g_game.level[4] = 2;
			g_game.level[5] = 1;
			g_game.level[6] = 2;
			
			g_game.level[8] = 2;
			g_game.level[9] = 1;
			g_game.level[10] = 2;
			g_game.level[12] = 1;
			g_game.level[13] = 2;
			g_game.level[14] = 1;
			
			g_game.levelThreshold = 2;
			g_game.player.y = 3;
			break;
		}
		
		case 10 :
		{
			g_game.level[0] = 1;
			
			g_game.level[4] = 1;
			g_game.level[5] = 1;
			
			g_game.level[8] = 2;
			
			g_game.level[12] = 2;
			
			g_game.level[16] = 3;
			g_game.level[17] = 2;
			
			g_game.level[20] = 3;
			g_game.level[21] = 3;
			
			g_game.levelThreshold = 3;
			g_game.player.y = 2;
			break;
		}
		
		case 40 :
		{
			g_game.level[0] = 1;
			g_game.level[1] = 1;
			g_game.level[2] = 1;
			
			g_game.level[4] = 1;
			
			g_game.levelThreshold = 4;
			g_game.player.y = 0;
			break;
		}
		
		default :
		{
			g_game.level[0] = 5;
			g_game.level[4] = 5;
			
			g_game.levelThreshold = 2;
			g_game.player.y = 2;
			
			g_game.levelNumber = 255;
			break;
		}
	}
	
	level_display();
}


/*
 * Background if you will
 */
void draw_playfield( void )
{
	// Clear screen
	const uint8_t blank[20] = {0,0,0,0,0,0,0,0,0,2,3,0,0,0,0,0,0,0,0,0};
	for( unsigned char i=0; i<18; i++ )
	{
		set_bkg_tiles( 0,i, 20,1, blank );
	}
	
	// Background
	const uint8_t tmp[20] = {8,9,8,9,8,9,8,9,0,0,0,0,8,9,8,9,8,9,8,9};
	set_bkg_tiles( 0,2, 20,1, tmp );
	set_bkg_tiles( 0,6, 20,1, tmp );
	set_bkg_tiles( 0,10, 20,1, tmp );
	set_bkg_tiles( 0,14, 20,1, tmp );
}


/*
 * Draw the correct crates where it should
 */
void level_display( void )
{
	uint8_t x = 0;
	uint8_t y = 0;
	uint8_t crate[4] = {12,13,14,15};
	
	for( uint8_t i=0; i<32; i++ )
	{
		// X coordinate
		x = i%8;
		// right side is 'backward'
		if( x > 3 )
		{
			x = 13-x;
		}
		x *= 2;
		
		// Y coordinate
		y = i/8;
		y *= 4;
		
		// Correct crate tiles
		if( g_game.level[i] > 0 )
		{
			uint8_t tmp = g_game.level[i]*4;
			crate[0] = 8+tmp;
			crate[1] = 9+tmp;
			crate[2] = 10+tmp;
			crate[3] = 11+tmp;
			
		}else{
			crate[0] = 0;
			crate[1] = 0;
			crate[2] = 0;
			crate[3] = 0;
		}
		
		// Update
		set_bkg_tiles( x,y, 2,2, crate );
	}
}


/*
 * Cleans up any sorted out crates groups
 */
void level_update( void )
{
	uint8_t crateType = 0;
	uint8_t crateNumber = 0;
	
	// Scans each rake
	for( int8_t rake=0; rake<32; rake+=4 )
	{
		// Start by the exterior and count how much crate of the same type there is
		crateType = 0;
		crateNumber = 0;
		uint8_t tmp = 0;
		
		for( uint8_t i=0; i<4; i++ )
		{
			tmp = rake + 3 - i;
			if( g_game.level[tmp] != 0 )
			{
				if( crateNumber < g_game.levelThreshold )
				{
					if( crateType == 0 )
					{
						crateType = g_game.level[tmp];
						crateNumber = 1;
					}else{
						if( g_game.level[tmp] == crateType )
						{
							crateNumber++;
						}else{
							//WARNING Wonky algo. Works because it's 3 or 4 crates...
							// Should stop as soon as not good anymore
							crateType = 0;
							crateNumber = 0;
						}
					}
				}
			}
		}
		
		// Check if the rake can be cleaned or not
		if( crateNumber >= g_game.levelThreshold )
		{
			uint8_t tmp = 0;
			uint8_t removed = 0;
			for( uint8_t i=0; i<4; i++ )
			{
				tmp = rake + 3 - i;
				if( g_game.level[tmp] != 0 )
				{
					if( removed < g_game.levelThreshold )
					{
						removed ++;
						g_game.level[tmp] = 0;
					}
				}
			}
		}
	}
}

/*
 * Checks if the level is completed or not
 */
uint8_t level_check_status( void )
{
	g_game.levelFinished = true;
	
	for( uint8_t i=0; i<32; i++ )
	{
		if( g_game.level[i] != 0 )
		{
			g_game.levelFinished = false;
		}
	}
}
