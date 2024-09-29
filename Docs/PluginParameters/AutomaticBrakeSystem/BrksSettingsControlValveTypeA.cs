namespace AtsPlugin.BrakeSystem
{
    public class BrksSettingsControlValveTypeA : AtsBehaviourSettingsBase
    {
        public double ArVolume { get; }
        public double SrVolume { get; }

        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double QcVolume { get; } = 3.5;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public bool RmModifiedValve { get; } = true;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public bool EnableQuickAction { get; } = false;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double SrOpeningRatio { get; } = 1.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double BcOpeningRatio { get; } = 1.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double BcExhaustOpeningRatio { get; } = 1.0;
    }
}
