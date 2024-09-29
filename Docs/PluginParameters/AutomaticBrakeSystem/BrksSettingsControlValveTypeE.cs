namespace AtsPlugin.BrakeSystem
{
    public class BrksSettingsControlValveTypeE : AtsBehaviourSettingsBase
    {
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double AcLimitingPressureKiloPascal { get; } = 441.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double AcExhaustOpeningRatio { get; } = 0.5;

        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double AcSupplyOpeningRatio { get; } = 0.03;

        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double QcVolume { get; } = 2.5;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double QscVolume { get; } = 1.0;

        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double QscValveOpeningRatio { get; } = 1.0;
    }
}
