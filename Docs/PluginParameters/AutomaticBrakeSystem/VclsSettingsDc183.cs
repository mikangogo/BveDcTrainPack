namespace AtsPlugin.VehicleSystem
{
    public class VclsSettingsDc183_C36 : AtsBehaviourSettingsBase
    {
        public double CompressorRpmReductionRatio { get; }
        public double CompressorSupplyLiterPerMinute { get; }
        public double GovernorStartKiloPascal { get; }
        public double GovernorStopKiloPascal { get; }
        public double MrPipeVolume { get; }
        public double BrakePipeVolume { get; }
        public double BcVolume { get; }
        public double PistonArea { get; }
        public double[] ShoeFriction { get; }

        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double BrakeMvOpeningRatio { get; } = 0.1;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double ReleaseMvOpeningRatio { get; } = 0.03;

        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveSupplyRatio { get; } = 0.1;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveExhaustRatio { get; } = 0.7;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveSupplyStartKiloPascal { get; } = 3.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveExhaustStartKiloPascal { get; } = 3.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValvePressureIntensifyingRatio { get; } = 1.37;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public bool IsEnabledPressureIntensifying { get; } = true;

        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double MaximumLoadRate { get; } = 1.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double MinimumBcPressureKiloPascal { get; } = 441.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double MaximumBcPressureKiloPascal { get; } = 548.8;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double InShotStartKiloPascal { get; } = 2.8;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double InShotEndKiloPascal { get; } = 35.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double InShotRate { get; } = 1.0;
    }
}
