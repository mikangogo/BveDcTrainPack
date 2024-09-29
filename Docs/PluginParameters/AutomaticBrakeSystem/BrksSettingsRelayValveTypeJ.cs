namespace AtsPlugin.BrakeSystem
{
    public class BrksSettingsRelayValveTypeJ : AtsBehaviourSettingsBase
    {
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveSupplyRatio { get; set; } = 0.1;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveExhaustRatio { get; set; } = 0.7;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveSupplyStartKiloPascal { get; set; } = 3.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveExhaustStartKiloPascal { get; set; } = 3.0;
    }
}
