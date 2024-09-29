namespace AtsPlugin.VehicleSystem
{
    public class VclsSettingsC26 : AtsBehaviourSettingsBase
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
        // ブレーキシリンダ　容積 [リットル]
        public double BcVolume { get; }
        // ブレーキシリンダ　ピストン受圧面積 [m2]
        public double PistonArea { get; }
        // 制輪子摩擦係数
        public double[] ShoeFriction { get; }

        // ブレーキ電磁弁　開度比率
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double BrakeMvOpeningRatio { get; } = 0.1;

        // 中継弁　供給量比率
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveSupplyRatio { get; } = 0.1;
        // 中継弁　排気量比率
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveExhaustRatio { get; } = 0.7;
        // 中継弁　供給位置開始差圧 [kPa]
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveSupplyStartKiloPascal { get; } = 3.0;
        // 中継弁　排気位置開始差圧 [kPa]
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double RelayValveExhaustStartKiloPascal { get; } = 3.0;

        // 応荷重装置　最大乗車率
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double MaximumLoadRate { get; } = 1.0;
        // 応荷重装置　空車時BC圧 [kPa]
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double MinimumBcPressureKiloPascal { get; } = 441.0;
        // 応荷重装置　積車時BC圧 [kPa]
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double MaximumBcPressureKiloPascal { get; } = 548.8;

        // 中継弁　インショット作用　開始圧力 [kPa]
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double InShotStartKiloPascal { get; } = 2.8;
        // 中継弁　インショット作用　終了圧力 [kPa]
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double InShotEndKiloPascal { get; } = 35.0;
        // 中継弁　インショット作用　比率
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double InShotRate { get; } = 1.0;
    }
}
