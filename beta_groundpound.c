//located in mario_actions_airborne.c

s32 act_ground_pound(struct MarioState *m) {
    u32 stepResult;
    f32 yOffset;

    play_sound_if_no_flag(m, SOUND_ACTION_THROW, MARIO_ACTION_SOUND_PLAYED);

        mario_set_forward_vel(m, 0.0f);

        set_mario_animation(m, MARIO_ANIM_START_GROUND_POUND);

        stepResult = perform_air_step(m, 0);
        if (stepResult == AIR_STEP_LANDED) {
            if (should_get_stuck_in_ground(m)) {
#ifdef VERSION_JP
                play_sound(SOUND_MARIO_OOOF, m->marioObj->header.gfx.cameraToObject);
#else
                play_sound(SOUND_MARIO_OOOF2, m->marioObj->header.gfx.cameraToObject);
#endif
                set_mario_action(m, ACT_BUTT_STUCK_IN_GROUND, 0);
            } else {
                play_mario_heavy_landing_sound(m, SOUND_ACTION_TERRAIN_HEAVY_LANDING);
                if (!check_fall_damage(m, ACT_HARD_BACKWARD_GROUND_KB)) {
                    set_mario_action(m, ACT_GROUND_POUND_LAND, 0);
                }
            }
            set_camera_shake_from_hit(SHAKE_GROUND_POUND);
        } else if (stepResult == AIR_STEP_HIT_WALL) {
            mario_set_forward_vel(m, -16.0f);
            if (m->vel[1] > 0.0f) {
                m->vel[1] = 0.0f;
            }

            set_mario_action(m, ACT_BACKWARD_AIR_KB, 0);
        }
    

    return FALSE;
}
