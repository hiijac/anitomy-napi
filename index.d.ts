export type ElementKind =
  | 'AudioTerm'
  | 'DeviceCompatibility'
  | 'Episode'
  | 'EpisodeTitle'
  | 'FileChecksum'
  | 'FileExtension'
  | 'Language'
  | 'Other'
  | 'ReleaseGroup'
  | 'ReleaseInformation'
  | 'ReleaseVersion'
  | 'Season'
  | 'Source'
  | 'Subtitles'
  | 'Title'
  | 'Type'
  | 'VideoResolution'
  | 'VideoTerm'
  | 'Volume'
  | 'Year';

export type Result = {
  [K in ElementKind]?: string
}

export declare function parse(input: string): Result;