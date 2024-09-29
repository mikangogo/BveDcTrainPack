namespace AtsPlugin.VehicleSystem
{
    public class VclsSettingsDer : AtsBehaviourSettingsBase
    {
        public double CompressorRpmReductionRatio { get; }
        public double CompressorSupplyLiterPerMinute { get; }
        public double GovernorStartKiloPascal { get; }
        public double GovernorStopKiloPascal { get; }
        public double MrPipeVolume { get; }
        public double BrakePipeVolume { get; }
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double MrVolume { get; } = 165.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double SrVolume { get; } = 165.0;
        public double BcVolume { get; }
        public double PistonArea { get; }
        public double[] ShoeFriction { get; }


        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveSupplyRatio { get; } = 0.1;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveExhaustRatio { get; } = 0.7;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveSupplyStartKiloPascal { get; } = 3.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveExhaustStartKiloPascal { get; } = 3.0;

        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double MaximumLoadRate { get; } = 1.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double MinimumBcPressureKiloPascal { get; } = 411.6;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double MaximumBcPressureKiloPascal { get; } = 539.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double InShotStartKiloPascal { get; } = 2.8;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double InShotEndKiloPascal { get; } = 0.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double InShotRate { get; } = 1.0;
    }
}
