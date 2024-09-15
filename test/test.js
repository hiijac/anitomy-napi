import anitomy from '@hiijac/anitomy-napi'

for (let i=0; i<10000; i++) {
  const r = anitomy.parse(`[GROUP] That Time I Was Reincarnated As A Compiler - ${i} [1080p].mkv`)
  console.log(r.Episode, i)
}