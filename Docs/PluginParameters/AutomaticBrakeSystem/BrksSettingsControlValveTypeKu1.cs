namespace AtsPlugin.BrakeSystem
{
    public class BrksSettingsControlValveTypeKu1 : AtsBehaviourSettingsBase
    {
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double AcLimitingPressureKiloPascal { get; } = 441.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double AcExhaustOpeningRatio { get; } = 0.1;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double AcSupplyOpeningRatio { get; } = 0.03;
        public double QcBpVolumeRatio { get; }
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double QcValveOpeningRatio { get; } = 0.25;
    }
}
