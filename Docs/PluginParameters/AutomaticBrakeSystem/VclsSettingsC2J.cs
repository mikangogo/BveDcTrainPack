namespace AtsPlugin.VehicleSystem
{
    public class VclsSettingsC2J : AtsBehaviourSettingsBase
    {
        // 圧縮機　回転数減速比率
        public double CompressorRpmReductionRatio { get; }
        // 圧縮機　供給量 [リットル/分]
        public double CompressorSupplyLiterPerMinute { get; }
        // 圧縮機　運転開始圧力 [kPa]
        public double GovernorStartKiloPascal { get; }
        // 圧縮機　運転終了圧力 [kPa]
        public double GovernorStopKiloPascal { get; }


        // 元空気だめ管　容積 [リットル]
        public double MrPipeVolume { get; }
        // ブレーキ管　容積 [リットル]
        public double BrakePipeVolume { get; }
        // ユルメ管　容積 [リットル]
        public double ReleasePipeVolume { get; }
        // 作用空気室 [リットル]
        public double AcVolume { get; }
        // 増圧シリンダ　容積 [リットル]
        public double PressureIntensifierVolume { get; }
        // ブレーキシリンダ　ピストン受圧面積 [m2]
        public double PistonArea { get; }
        // 制輪子摩擦係数
        public double[] ShoeFriction { get; }

        // ブレーキ電磁弁　開度比率
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double BrakeMvOpeningRatio { get; } = 0.1;
    }
}
