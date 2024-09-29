namespace AtsPlugin.BrakeSystem
{
    public class BrksSettingsM23 : AtsBehaviourSettingsBase
    {
        /// <summary>
        /// ブレーキ弁　釣合ピストン　ブレーキ管　排気比率
        /// </summary>
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double BpEqPistonExhaustOpeningRatio { get; } = 1.0;
        /// <summary>
        /// ブレーキ弁　釣合ピストン　釣合管　ブレーキ管　込め溝開度比率
        /// </summary>
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double BpErEqPistonOpeningRatio { get; } = 0.05;
        /// <summary>
        /// ブレーキ弁　釣合管　排気開度比率
        /// </summary>
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double ErExhaustOpeningRatio { get; } = 0.5;
        /// <summary>
        /// ブレーキ弁　ブレーキ管　常用ブレーキ位置　排気比率
        /// </summary>
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double BpExhaustOpeningRatio { get; } = 0.1;
        /// <summary>
        /// ブレーキ弁　ブレーキ管　非常ブレーキ位置　排気比率
        /// </summary>
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double EmergencyBpExhaustOpeningRatio { get; } = 7.0;
        /// <summary>
        /// ブレーキ弁　ブレーキ管　緩め込め位置　開度比率
        /// </summary>
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double BpChargingOpeningRatio { get; } = 0.4;
        /// <summary>
        /// ブレーキ弁　釣合管　緩め込め位置　開度比率
        /// </summary>
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double ErChargingOpeningRatio { get; } = 0.5;
        /// <summary>
        /// ブレーキ弁　釣合空気だめ 容積 [リットル]
        /// </summary>
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double ErVolume { get; } = 15.0;
        /// <summary>
        /// ブレーキ弁　ユルメ管　排気開度比率
        /// </summary>
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RpExhaustOpeningRatio { get; } = 1.0;
    }
}
