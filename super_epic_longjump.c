//located in mario_actions_airborne.c

s32 act_long_jump(struct MarioState *m) {
    s32 animation;
    if (!m->marioObj->oMarioLongJumpIsSlow) {
        animation = MARIO_ANIM_FAST_LONGJUMP;
    } else {
        animation = MARIO_ANIM_SLOW_LONGJUMP;
    }

    play_mario_sound(m, SOUND_GENERAL_BOWSER_BOMB_EXPLOSION, SOUND_MARIO_YAHOO);

    if (m->floor->type == SURFACE_VERTICAL_WIND && m->actionState == 0) {
        play_sound(SOUND_MARIO_HERE_WE_GO, m->marioObj->header.gfx.cameraToObject);
        m->actionState = 1;
    }

    common_air_action_step(m, ACT_LONG_JUMP_LAND, animation, AIR_STEP_CHECK_LEDGE_GRAB);
    if (common_air_action_step) {
        m->vel[1] += 1.5f;
    print_text_centered(160, 40, "SUPER EPIC LONG JUMP");
    set_environmental_camera_shake(SHAKE_ENV_BOWSER_JUMP);
    }
    return FALSE;
}
