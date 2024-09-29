namespace AtsPlugin.VehicleSystem
{
    public class VclsSettingsDae : AtsBehaviourSettingsBase
    {
        public double BcVolume { get; }
        public double CompressorRpmReductionRatio { get; }
        public double CompressorSupplyLiterPerMinute { get; }
        public double GovernorStartKiloPascal { get; }
        public double GovernorStopKiloPascal { get; }
        public double MrPipeVolume { get; }
        public double BrakePipeVolume { get; }
        public double ReleasePipeVolume { get; }
        public double PistonArea { get; }
        public double[] ShoeFriction { get; }

        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double BrakeMvOpeningRatio { get; } = 0.1;
    }
}
