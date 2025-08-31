#ifndef _FILE_SFX_
#define _FILE_SFX_

typedef enum {
	sfx_eyup,
	sfx_nope,
	sfx_grab,
	sfx_put,
	sfx_win
} sfx_list;

void play_SFX( sfx_list sfx )
{
	switch( sfx )
	{
		case sfx_grab :
		{
			NR10_REG=0x15;
			NR11_REG=0x80;
			NR12_REG=0x43;
			NR13_REG=0x7B;
			NR14_REG=0x86;
			break;
		}
		case sfx_put :
		{
			NR41_REG = 0x1B;
			NR42_REG = 0xF9;
			NR43_REG = 0xA0;
			NR44_REG = 0xC0;
			break;
		}
		case sfx_nope :
		{
			NR41_REG=0x3A;
			NR42_REG=0xA1;
			NR43_REG=0x62;
			NR44_REG=0xC0;
			break;
		}
		default:break;
	}
}

#endif
