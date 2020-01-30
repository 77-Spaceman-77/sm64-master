//located in bowser.inc.c

void func_802B5C78(void) {
    if (BITS)
        gSecondCameraFocus = spawn_object(o, MODEL_STAR, bhvGrandStar);
    else {
        spawn_object(o, MODEL_BOWSER_FLAMES, bhvBowserBombExplosion);
        set_environmental_camera_shake(SHAKE_ENV_BOWSER_JUMP);
        set_environmental_camera_shake(SHAKE_ENV_BOWSER_JUMP);
        set_environmental_camera_shake(SHAKE_ENV_BOWSER_JUMP);
        spawn_object_loot_yellow_coins(o, 10, 1.0f);
        play_sound(SOUND_GENERAL_BOWSER_BOMB_EXPLOSION, gDefaultSoundArgs);
        mark_object_for_deletion(o);
    }
}

s32 func_802B5F20(void) {
    s32 ret = 1;
o->oAction = BOBOMB_ACT_EXPLODE; 
    return ret;
}
