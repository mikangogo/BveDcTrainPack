namespace AtsPlugin.VehicleSystem
{
    public class VclsSettingsDe : AtsBehaviourSettingsBase
    {
        public double CompressorRpmReductionRatio { get; }
        public double CompressorSupplyLiterPerMinute { get; }
        public double GovernorStartKiloPascal { get; }
        public double GovernorStopKiloPascal { get; }
        public double MrPipeVolume { get; }
        public double BrakePipeVolume { get; }
        public double PistonArea { get; }
        public double[] ShoeFriction { get; }

        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double MrVolume { get; } = 165.0;
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double SrVolume { get; } = 165.0;

        public double BcVolume { get; }
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double ReleasePipeVolume { get; } = 0.0;         //ユルメ管容積「0」でユルメ管の接続なし

        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double BrakeMvOpeningRatio { get; } = 0.1;

        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public bool HasBrakeMv { get; } = false;

        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public bool HasBrakeCircuit { get; } = false;
    }
}
